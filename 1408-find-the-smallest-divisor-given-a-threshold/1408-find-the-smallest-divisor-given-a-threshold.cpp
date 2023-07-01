class Solution {
public:
    bool valid(vector<int>& nums, int threshold,int mid,int n){
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += ceil((1.0*nums[i])/mid);
            if(sum > threshold)return false;
        }
        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size(),mn = 1,mx = INT_MIN;
        for(int i = 0;i<n;i++){
            mx = max(mx,nums[i]);
        }
        int res = mx;
        while(mn <= mx){
            int mid = (mx+mn)/2;
            if(valid(nums,threshold,mid,n)){
                res = mid;
                mx = mid-1;
            }
            else mn = mid + 1;
        }
        return res;
    }
};