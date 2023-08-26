class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(),j = n-1,i=0;
        while(i<=j){
            int mid = (i+j)/2;
            int l = 1;
            if((mid-i)%2==0) l = 2;
            int m = 0;
            if(mid+1 < n && nums[mid] == nums[mid+1]) m = 1;
            else if(mid > 0 && nums[mid] == nums[mid-1]) m = -1;
            else return nums[mid];
            if(l == 2){
                if(m == 1){
                    i = mid+2;
                }
                else{
                    j = mid-2;
                }
            }
            else{
                if(m == 1){
                    j = mid-1;
                }
                else{
                    i = mid+1;
                }
            }
        }
        return 0;
    }
};