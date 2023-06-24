// 97. Interleaving String
// Medium
// 6.5K
// 392
// Companies
// Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

// An interleaving of two strings s and t is a configuration where s and t are divided into n and m 
// substrings
//  respectively, such that:

// s = s1 + s2 + ... + sn
// t = t1 + t2 + ... + tm
// |n - m| <= 1
// The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
// Note: a + b is the concatenation of strings a and b.

 

// Example 1:


// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output: true
// Explanation: One way to obtain s3 is:
// Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
// Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
// Since s3 can be obtained by interleaving s1 and s2, we return true.
// Example 2:

// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// Output: false
// Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.
// Example 3:

// Input: s1 = "", s2 = "", s3 = ""
// Output: true
 

// Constraints:

// 0 <= s1.length, s2.length <= 100
// 0 <= s3.length <= 200
// s1, s2, and s3 consist of lowercase English letters.
 

// Follow up: Could you solve it using only O(s2.length) additional memory space?


//Recursion 
#include "/Users/swagatswaroopparida/stdc.h"
using namespace std;

bool isInter(string& s1,string& s2,string& s3,int i,int j,int k){
        if(i == s1.size())return s2.substr(j) == s3.substr(k);
        else if(j == s2.size())return s1.substr(i) == s3.substr(k);
        bool l = false,o = false;
        if(s1[i] == s3[k])l = isInter(s1,s2,s3,i+1,j,k+1);
        if(s2[j] == s3[k])o = isInter(s1,s2,s3,i,j+1,k+1);
        return l || o;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(),m = s2.size(),k = s3.size();
        if(k != m+n)return false;
        return isInter(s1,s2,s3,0,0,0);
    }

int main(){

    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbbaccc";
    cout<<isInterleave(s1,s2,s3)<<endl;
    return 0;
}

//Memotization
class Solution {
public:
    bool isInter(string& s1,string& s2,string& s3,int i,int j,int k,vector<vector<int>>& v){
        if(i == s1.size())return s2.substr(j) == s3.substr(k);
        else if(j == s2.size())return s1.substr(i) == s3.substr(k);
        if(v[i][j] != -1)return v[i][j];
        bool l = 0,o = 0;
        if(s1[i] == s3[k])l = isInter(s1,s2,s3,i+1,j,k+1,v);
        if(s2[j] == s3[k])o = isInter(s1,s2,s3,i,j+1,k+1,v);
        return v[i][j] = l || o;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(),m = s2.size(),k = s3.size();
        vector<vector<int>> v(n,vector<int>(m,-1));
        if(k != m+n)return false;
        return isInter(s1,s2,s3,0,0,0,v);
    }
};


//Memotization with optimizatin
class Solution {
public:
    bool isInter(string& s1,string& s2,string& s3,int i,int j,int k,vector<vector<int>>& v){
        if(i == s1.size())return v[i][j] = s2.substr(j) == s3.substr(k);
        else if(j == s2.size())return v[i][j] = s1.substr(i) == s3.substr(k);
        if(v[i][j] != -1)return v[i][j];
        bool l = 0,o = 0;
        if(s1[i] == s3[k])l = isInter(s1,s2,s3,i+1,j,k+1,v);
        if(s2[j] == s3[k])o = isInter(s1,s2,s3,i,j+1,k+1,v);
        return v[i][j] = l || o;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(),m = s2.size(),k = s3.size();
        vector<vector<int>> v(n+1,vector<int>(m+1,-1));
        if(k != m+n)return false;
        return isInter(s1,s2,s3,0,0,0,v);
    }
};

//Tabulation
