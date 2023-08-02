class Solution {
public:
    void p(vector<int>& nums,vector<int> v1,vector<vector<int>>& v,int i){
        if(i == nums.size()){
            v.push_back(v1);
            return;
        }
        int n = v1.size();
        for(int j = 0;j<=n;j++){
            v1.insert(v1.begin()+j,nums[i]);
            p(nums,v1,v,i+1);
            v1.erase(v1.begin()+j);
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> v1;
        p(nums,v1,v,0);
        return v;
    }
};