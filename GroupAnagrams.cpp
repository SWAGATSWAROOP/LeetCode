// 49. Group Anagrams
// Medium
// 14.6K
// 425
// Companies
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Example 2:

// Input: strs = [""]
// Output: [[""]]
// Example 3:

// Input: strs = ["a"]
// Output: [["a"]]
 

// Constraints:

// 1 <= strs.length <= 104
// 0 <= strs[i].length <= 100
// strs[i] consists of lowercase English letters.
// Accepted
// 1.9M
// Submissions
// 2.8M
// Acceptance Rate
// 66.7%

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> st;
        vector<vector<string>> v;
        int n = strs.size();
        for(int i = 0;i<n;i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            st[s].push_back(strs[i]);
        }
        for(auto x:st){
            v.push_back(x.second);
        }
        return v;
    }
};