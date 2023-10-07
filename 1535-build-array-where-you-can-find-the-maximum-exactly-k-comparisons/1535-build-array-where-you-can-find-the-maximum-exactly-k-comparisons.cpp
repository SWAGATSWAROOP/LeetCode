class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        long long dp[m + 1][k + 1];
        long long prefix[m + 1][k + 1];
        long long prevDp[m + 1][k + 1];
        long long prevPrefix[m + 1][k + 1];
        memset(dp, 0, sizeof(dp));
        memset(prefix, 0, sizeof(prefix));
        memset(prevDp, 0, sizeof(prevDp));
        memset(prevPrefix, 0, sizeof(prevPrefix));
        int MOD = 1e9 + 7;
        
        for (int num = 1; num <= m; num++) {
            dp[num][1] = 1;
        }
        
        for (int i = 1; i <= n; i++) {
            if (i > 1) {
                memset(dp, 0, sizeof(dp));
            }
            
            memset(prefix, 0, sizeof(prefix));
            
            for (int maxNum = 1; maxNum <= m; maxNum++) {
                for (int cost = 1; cost <= k; cost++) {
                    long long ans = (maxNum * prevDp[maxNum][cost]) % MOD;
                    ans = (ans + prevPrefix[maxNum - 1][cost - 1]) % MOD;

                    dp[maxNum][cost] += ans;
                    dp[maxNum][cost] %= MOD;
                    
                    prefix[maxNum][cost] = (prefix[maxNum - 1][cost] + dp[maxNum][cost]);
                    prefix[maxNum][cost] %= MOD;
                }
            }
            
            // Can't reassign long long[][] in C++, need to manually override
            for (int maxNum = 0; maxNum <= m; maxNum++) {
                for (int cost = 0; cost <= k; cost++) {
                    prevDp[maxNum][cost] = dp[maxNum][cost];
                    prevPrefix[maxNum][cost] = prefix[maxNum][cost];
                }
            }
        }
        
        return prefix[m][k];
    }
};