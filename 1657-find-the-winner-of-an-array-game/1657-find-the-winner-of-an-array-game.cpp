class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k >= arr.size())return *max_element(arr.begin(),arr.end());
        queue<int> q;
        for(int i = 1;i<arr.size();i++)q.push(arr[i]);
        int first = arr[0];
        int i = 0;
        while(i != k){
            if(first > q.front()){
                int top = q.front();
                q.push(top);
                i++;
            }
            else{
                q.push(first);
                first = q.front();
                i = 1;
            }
            cout<<first<<endl;
            q.pop();
        }
        return first;
    }
};