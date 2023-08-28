class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(arr.back()-arr.size() < k)return k + arr.size();
        if(arr.front() > k)return k;
        int i = 0,j = arr.size()-1,mid;
        while(i <= j){
            mid = i + (j-i)/2;
            if(arr[mid] - mid - 1 < k)i = mid + 1;
            else j = mid - 1;
        }
        if(arr[mid] - mid - 1 >= k)return mid + k;
        return mid + k + 1;
    }
};