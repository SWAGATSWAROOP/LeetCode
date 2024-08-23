class Solution {
public:
    void generateSubset(vector<int>& nums,vector<vector<int>>& ans,vector<int>& temp,int i){
        if(i == nums.size()){
            ans.push_back(temp);
            return;
        }
        generateSubset(nums,ans,temp,i+1);
        temp.push_back(nums[i]);
        generateSubset(nums,ans,temp,i+1);
        temp.pop_back();
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        generateSubset(nums,ans,temp,0);
        return ans;
    }
};