class Solution {
public:
    int lengthofLIS(vector<int>& nums,int prev,int currindex,int n,vector<vector<int>>& v){
        if(currindex == n)return 0;
        int k = 0;
        if(v[prev+1][currindex])return v[prev+1][currindex];
        if(prev == -1 || nums[prev] < nums[currindex])k = 1+lengthofLIS(nums,currindex,currindex+1,n,v);
        int l = lengthofLIS(nums,prev,currindex+1,n,v);
        return v[prev+1][currindex] = max(k,l);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v(n+1,vector<int>(n,0));
        return lengthofLIS(nums,-1,0,n,v);
    }
};

/*
Memotization O(n^2) and O(n) stack Space 
*/


