class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int mx1 = 0,mx2 = 0,mn1 = 1e5,mn2 = 1e5,n = nums.size();
        for(int i = 0;i<n;i++){
            if(mx1 < nums[i]){
                mx2 = mx1;
                mx1 = nums[i];
            }
            else if(mx2 < nums[i])mx2 = nums[i];
            if(mn1 > nums[i]){
                mn2 = mn1;
                mn1 = nums[i];
            }
            else if(mn2 > nums[i])mn2 = nums[i];
        }
        return (mx1*mx2) - (mn1*mn2);
    }
};