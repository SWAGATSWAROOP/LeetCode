class Solution {
public:
    bool mn(vector<int>& nums, int p,int mid){
        int index = 1;
        while(index < nums.size()){
            if(nums[index]-nums[index-1] <= mid){
                p--;
                index++;
                if(!p)return true;
            }
            index++;
        }
        return false;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n = nums.size()-1,i = 0;
        int mxd = nums[n] - nums[0];
        int ans = 0;
        while(i <= mxd){
            int mid = i + (mxd-i)/2;
            if(mn(nums,p,mid)){
                ans = mid;
                mxd = mid-1;
            }
            else i = mid + 1;
        }
        return ans;
    }
};