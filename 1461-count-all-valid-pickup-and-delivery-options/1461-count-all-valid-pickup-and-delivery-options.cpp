class Solution {
private:
    const int MOD=1e9+7;
public:
    int countOrders(int n) {
        int ans=1;
        for(int i=1;i<=n;++i) ans = ( 1LL * ans%MOD * (2*i-1)*i )%MOD;
        return ans;
    }
};       