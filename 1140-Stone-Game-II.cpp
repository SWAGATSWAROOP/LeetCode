class Solution {
public:
    int stonegame(vector<int>& piles,int index,int M,int turn,vector<vector<vector<int>>>& dp){
        if(index == piles.size())return 0;
        if(dp[index][M][turn] != -1)return dp[index][M][turn];
        int j = index;
        int k = 2*M;
        int l = 1;
        int sum = 0,functionCall;
        if(turn == 1){
            int ans = -1;
            while(j < piles.size() && l <= k){
                sum += piles[j];
                functionCall = sum + stonegame(piles,j+1,max(M,l),0,dp);
                ans = max(ans,functionCall);
                l++;
                j++;
            }
            return dp[index][M][turn] = ans;
        }
        int ans = 1e9;
        while(j < piles.size() && l <= k){
            functionCall = stonegame(piles,j+1,max(M,l),1,dp);
            ans = min(ans,functionCall);
            l++;
            j++;
        }
        return dp[index][M][turn] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        vector<vector<vector<int>>> dp(piles.size()+1,vector<vector<int>>((2*(piles.size()+1)),vector<int>(2,-1)));
        return stonegame(piles,0,1,1,dp);
    }
};