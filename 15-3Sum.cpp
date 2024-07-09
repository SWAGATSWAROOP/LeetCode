class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int sz = nums.size()-3,k,j,req,sum,curr;
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        for(int i = 0;i <= sz;){
            k = i+1,j = sz+2;
            curr = nums[i];
            req = -1*curr;
            while(k < j){
                sum = nums[k] + nums[j];
                if(sum == req){
                    v.push_back({nums[i],nums[k],nums[j]});
                    k++;
                    j--;
                    while(k < j && nums[k] == nums[k-1])k++;
                    while(j > k && nums[j] == nums[j+1])j--;
                }
                else if(sum > req)j--;
                else k++;
            }
            while(i <= sz && curr == nums[i])i++;
        }
        return v;
    }
};