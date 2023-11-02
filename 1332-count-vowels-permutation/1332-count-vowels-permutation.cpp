class Solution {
public:
    int countVowelPermutation(int n) {
        long long a = 1,e = 1,i = 1,o = 1,u = 1;
        long long a1,e1,i1,o1,u1;
        int mod = 1e9+7;
        for(int j = 2;j<=n;j++){
            a1 = (e+(i+u)%mod)%mod;
            e1 = (i + a)%mod;
            i1 = (e+o)%mod;
            o1 = i%mod;
            u1 = (o+i)%mod;
            a = a1,e = e1,i = i1,u = u1,o = o1;
        }
        return (a+e+i+o+u)%mod;
    }
};
