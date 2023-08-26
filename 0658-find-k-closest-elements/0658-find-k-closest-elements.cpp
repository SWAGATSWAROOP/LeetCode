class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i = 0,j = arr.size()-1;
        int mid = 0;
        while(i <= j){
            mid = i + (j-i)/2;
            if(arr[mid] == x)break;
            else if(arr[mid] > x)j = mid - 1;
            else i = mid + 1;
        }
        priority_queue<int,vector<int>,greater<int>> pq;
        if(arr[mid] > x)mid--;
        vector<int> v;
        int m = mid,l = mid+1;
        while(k && m >=0 && l < arr.size()){
            int a = abs(arr[m] - x);
            int b = abs(arr[l] - x);
            if(a > b)pq.push(arr[l++]);
            else pq.push(arr[m--]);
            k--;
        }
        if(k){
            if(l >= arr.size()){
                while(k--)pq.push(arr[m--]);
            }
            else while(k--)pq.push(arr[l++]);
        }
        while(!pq.empty()){
            v.push_back(pq.top());
            pq.pop();
        }
        return v;
    }
};