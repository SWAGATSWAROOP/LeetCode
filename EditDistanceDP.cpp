// Hard
// 12.6K
// 144
// Companies
// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character
 

// Example 1:

// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
// Example 2:

// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation: 
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')
 

// Constraints:

// 0 <= word1.length, word2.length <= 500
// word1 and word2 consist of lowercase English letters.
// Accepted
// 653.2K
// Submissions
// 1.2M
// Acceptance Rate
// 54.7%


//Space O(mn)+O(min(m,n)) Memotization 
class Solution {
public:
    int mD(string word1,string word2,vector<vector<int>>& v,int m,int n){
        if(!m || !n){
            int l = m == 0 ? n:m;
            return v[m][n] = l;
        }
        if(v[m][n]!=-1)return v[m][n];
        int l,z,k;
        l = mD(word1,word2,v,m-1,n-1);
        z = 1+ mD(word1,word2,v,m,n-1);
        k = 1+ mD(word1,word2,v,m-1,n);
        if(word1[n-1] != word2[m-1])l += 1;
        return v[m][n] = min(l,min(z,k));
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(),m = word2.size();
        vector<vector<int>> v(m+1,vector<int>(n+1,-1));
        return mD(word1,word2,v,m,n);
    }
};

//Bottom to up Tabulation Dp o(mn) Space O(mn)

class Solution
{
public:
    vector<vector<int>> memo;
    int minDistance(string word1, string word2)
    {
        int word1Length = word1.size();
        int word2Length = word2.size();
        if (word1Length == 0)
        {
            return word2Length;
        }
        if (word2Length == 0)
        {
            return word1Length;
        }
        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));
        for (int word1Index = 1; word1Index <= word1Length; word1Index++)
        {
            dp[word1Index][0] = word1Index;
        }
        for (int word2Index = 1; word2Index <= word2Length; word2Index++)
        {
            dp[0][word2Index] = word2Index;
        }
        for (int word1Index = 1; word1Index <= word1Length; word1Index++)
        {
            for (int word2Index = 1; word2Index <= word2Length; word2Index++)
            {
                if (word2[word2Index - 1] == word1[word1Index - 1])
                {
                    dp[word1Index][word2Index] = dp[word1Index - 1][word2Index - 1];
                }
                else
                {
                    dp[word1Index][word2Index] = min(dp[word1Index - 1][word2Index],
                                                     min(dp[word1Index][word2Index - 1],
                                                         dp[word1Index - 1][word2Index - 1])) +
                                                 1;
                }
            }
        }

        return dp[word1Length][word2Length];
    }
};