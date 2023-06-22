//Recursive Soln
class Solution {
public:
    int minD(string& s1,string& s2,int i,int j,int n,int m){
        if(i == n || j == m){
            int sum = 0;
            if(j == m)for(;i<n;i++)sum += s1[i];
            else for(;j<m;j++)sum += s2[j];
            return sum;
        }
        if(s1[i] == s2[j])return minD(s1,s2,i+1,j+1,n,m);
        return min(s1[i] + minD(s1,s2,i+1,j,n,m),s2[j] + minD(s1,s2,i,j+1,n,m));
    }

    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(),m = s2.size();
        return minD(s1,s2,0,0,n,m);
    }
};

//Memotization
class Solution {
public:
    int minD(string& s1,string& s2,int i,int j,int n,int m){
        if(i == n || j == m){
            int sum = 0;
            if(j == m)for(;i<n;i++)sum += s1[i];
            else for(;j<m;j++)sum += s2[j];
            return sum;
        }
        if(s1[i] == s2[j])return minD(s1,s2,i+1,j+1,n,m);
        return min(s1[i] + minD(s1,s2,i+1,j,n,m),s2[j] + minD(s1,s2,i,j+1,n,m));
    }

    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(),m = s2.size();
        return minD(s1,s2,0,0,n,m);
};

//Tabulation With Space Optimization
// const static auto initialize = [] { std::ios::sync_with_stdio(false); 
// std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(),m = s2.size();
        vector<int> v(m+1,0);
        for(int i = m-1;i>=0;i--)v[i] = v[i+1] + s2[i];
        for(int i = n-1;i>=0;i--){
            int prev = v[m];
            v[m] += s1[i];
            for(int j = m-1;j>=0;j--){
                int temp = v[j];
                if(s1[i] == s2[j])v[j] = prev;
                else v[j] = min(s2[j]+v[j+1],s1[i]+v[j]);
                prev = temp;
            }
        }
        return v[0];
    }
};
