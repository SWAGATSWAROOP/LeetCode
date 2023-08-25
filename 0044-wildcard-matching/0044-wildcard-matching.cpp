class Solution {
public:
    int match(string& s,string& p,int i,int j,vector<vector<int>>& dp){
        if(i < 0){
            if(j < 0)return true;
            if(p[j]!='*')return false;
            while(j>=0 && p[j] == '*')j--;
            if(j < 0)return true;
            return false;
        }
        if(i < 0 || j < 0)return false;
        if(dp[i][j] != -1)return dp[i][j];
        if(s[i] == p[j] || p[j] == '?')return dp[i][j] = match(s,p,i-1,j-1,dp);
        else if(p[j] == '*')return dp[i][j] = match(s,p,i-1,j,dp) || match(s,p,i,j-1,dp);
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(),vector<int>(p.size(),-1));
        return match(s,p,s.size()-1,p.size()-1,dp);
    }
};