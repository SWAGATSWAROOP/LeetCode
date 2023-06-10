// drome
// Hard
// 4.2K
// 59
// Companies
// Given a string s. In one step you can insert any character at any index of the string.

// Return the minimum number of steps to make s palindrome.

// A Palindrome String is one that reads the same backward as well as forward.

 

// Example 1:

// Input: s = "zzazz"
// Output: 0
// Explanation: The string "zzazz" is already palindrome we do not need any insertions.
// Example 2:

// Input: s = "mbadm"
// Output: 2
// Explanation: String can be "mbdadbm" or "mdbabdm".
// Example 3:

// Input: s = "leetcode"
// Output: 5
// Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 

// Constraints:

// 1 <= s.length <= 500
// s consists of lowercase English letters.
// Accepted
// 122.9K
// Submissions
// 177.6K
// Acceptance Rate
// 69.2%

class Solution {
public:
    int minR(vector<vector<int>>& v,string& s,int i,int j,int n){
        if(j<=i)return 0;
        if(v[i][j] != -1)return v[i][j];
        else if(s[i] != s[j])v[i][j] = 1+min(minR(v,s,i+1,j,n),minR(v,s,i,j-1,n));
        else v[i][j] = minR(v,s,i+1,j-1,n);
        return v[i][j];
    }

    // Got Memory Limit Exceeded  due to not passing string as reference 

    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> v(n,vector<int>(n,-1));
        return minR(v,s,0,n-1,n);;
    }
};