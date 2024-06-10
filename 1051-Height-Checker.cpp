class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count = 0,n = heights.size();
        vector<int> ans = heights;
        sort(ans.begin(),ans.end());
        for(int i = 0;i < n;i++){
            if(ans[i] != heights[i])count++;
        }
        return count;
    }
};