class Solution {
public:
    bool isvalid(vector<int>& weights,int days,int mid,int n){
        int sum = 0,count = 1;
        for(int i=0;i<n;i++){
            sum += weights[i];
            if(sum > mid){
                sum = weights[i];
                count++;
            }
            if(count > days)return false;
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size(),sum = 0,mn = 0;
        for(int i =0;i<n;i++){
            sum += weights[i];
            mn = max(mn,weights[i]);
        }
        if(n == days)return mn;
        int res = mn;
        while(mn <= sum){
            int mid = (mn+sum)/2;
            if(isvalid(weights,days,mid,n)){
                res = mid;
                sum = mid - 1;
            }
            else mn = mid+1;
        }
        return res; 
    }
};