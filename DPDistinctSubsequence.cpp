// Hard
// 5.5K
// 204
// Companies
// Given two strings s and t, return the number of distinct 
// subsequences
//  of s which equals t.

// The test cases are generated so that the answer fits on a 32-bit signed integer.

 

// Example 1:

// Input: s = "rabbbit", t = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from s.
// rabbbit
// rabbbit
// rabbbit
// Example 2:

// Input: s = "babgbag", t = "bag"
// Output: 5
// Explanation:
// As shown below, there are 5 ways you can generate "bag" from s.
// babgbag
// babgbag
// babgbag
// babgbag
// babgbag
 

// Constraints:

// 1 <= s.length, t.length <= 1000
// s and t consist of English letters.
// Accepted
// 299.9K
// Submissions
// 668.4K
// Acceptance Rate
// 44.9%

const static auto initialize = [] { std::ios::sync_with_stdio(false); 
std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

class Solution {
public:
    int Distinct(vector<vector<int>>& v,string s,string t,int i,int j,int n,int m){
        if(j == m)return 1;
        // This or condition is very important it solves TLE
        if(i == n || n-i+1 < m-j+1)return 0; 
        if(v[i][j] != -1)return v[i][j];
        int k = s[i] == t[j] ? Distinct(v,s,t,i+1,j+1,n,m) : 0;
        int o = Distinct(v,s,t,i+1,j,n,m);
        return v[i][j] = k+o;
    }

    int numDistinct(string s, string t) {
        int n = s.size(),m = t.size();
        vector<vector<int>> v(n+1,vector<int>(m+1,-1));
        return Distinct(v,s,t,0,0,n,m);
    }
};