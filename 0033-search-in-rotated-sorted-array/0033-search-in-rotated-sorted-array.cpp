class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0,j = nums.size()-1,n = j;
        bool left = nums[0] <= target;
        bool right = nums[n] >= target;
        if(!left && !right)return -1;
        while(i <= j){
            int mid = i + (j-i)/2;
            if(nums[mid] == target)return mid;
            else if(target > nums[mid]){
                if(!left && right || (left && nums[mid] >= nums[0]))i = mid + 1;
                else j = mid - 1;
            }
            else{
                if(left && !right || (right && nums[mid] <= nums[n]))j = mid - 1;
                else i = mid + 1;
            }
        }
        return -1;
    }
};