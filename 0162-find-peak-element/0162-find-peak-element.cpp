class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i = 0,j = nums.size()-1;
        while(i < j){
            int mid = i + (j-i)/2;
            if(mid != 0 && mid != nums.size()-1 && nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]){
                return mid;
            }
            else if((mid != 0 && nums[mid-1] > nums[mid]) || (mid == 0 && nums[mid] > nums[mid+1]))j = mid-1;
            else i = mid+1;
        }
        return i == 0 ? i:j;
    }
};