class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i = 0,n = nums.size()-1,j = n;
        while(i <= j){
            int mid = i + (j-i)/2;
            if(nums[mid] == target)return true;
            while(i <= mid && nums[mid] == nums[i])i++;
            while(j >= mid && nums[mid] == nums[j])j--;
            if(i > mid || j < mid)continue;
            bool left = target >= nums[i] ? true:false;
            bool right = target <= nums[j] ? true:false;
            if(nums[mid] > target){
                if(right && !left && nums[mid] > nums[j])i = mid+1;
                else j = mid - 1;
            }
            else{
                if(left && !right && nums[mid] < nums[i])j = mid - 1;
                else i = mid + 1;
            }
        }
        return false;
    }
};