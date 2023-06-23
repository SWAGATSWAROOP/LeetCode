/*139. Word Break
Medium
14.3K
603
Companies
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

/*
 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 

Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
Accepted
1.4M
Submissions
3M
Acceptance Rate
45.7%*/

//Memotization After Sol
class Solution {
public:
    int wB(int i,string& s,vector<string>& wordDict,vector<int>& res){
        if(i == s.size())return 1;
        if(res[i]!=-1)return res[i];
        string temp;
        for(int j = i;j<s.size();j++){
            temp += s[j];
            if(find(wordDict.begin(),wordDict.end(),temp)!=wordDict.end())if(wB(j+1,s,wordDict,res))return res[i] = 1;
        }
        return res[i] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> res(s.size(),-1);
        return wB(0,s,wordDict,res);
    }
};

//Tabulation Done On My Own Don't Know beats
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> res(n+1,0);
        res[n] = 1;
        for(int i = n-1;i>=0;i--){
            for(int j = 1;j<=n-i;j++){
                if(find(wordDict.begin(),wordDict.end(),s.substr(i,j)) != wordDict.end() && res[i+j]){
                    res[i] = 1;
                    break;
                }
            }
        }
        return res[0];
    }
};

