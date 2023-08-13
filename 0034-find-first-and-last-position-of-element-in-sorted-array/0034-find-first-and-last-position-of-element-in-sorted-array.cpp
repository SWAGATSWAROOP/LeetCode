class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v(2,-1);
        int i = 0;
        int j = nums.size()-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(nums[mid] == target){
                v[0] = mid;
                v[1] = mid;
                int l = mid - 1;
                while(l >= 0 && nums[l]==target){
                    v[0] = l--;
                }
                l = mid+1;
                while(l < nums.size() && nums[l] == target){
                    v[1] = l++;
                }
                return v;
            }
            else if(nums[mid] > target){
                j = mid-1;
            }
            else{
                i = mid+1;
            }
        }
        return v;
    }
};