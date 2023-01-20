// 3. Longest Substring Without Repeating Characters
// Medium
// 31.5K
// 1.4K
// Companies
// Given a string s, find the length of the longest 
// substring
//  without repeating characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.
// Accepted
// 4.2M
// Submissions
// 12.4M
// Acceptance Rate
// 33.8%

#include<unordered_map>
#include<unordered_set>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()){
            return 0;
        }
        unordered_map<char,int> map;
        int count =1;
        int mx = 1;
        int low = 0;
        map[s[0]] = 0;
        for(int i=1;i<s.length();i++){
            if(map.count(s[i])>0){
                count = i - map[s[i]];
                for(int j = low; j<map[s[i]];j++){
                    if(map.count(s[j])>0 && map[s[j]]<map[s[i]]){
                        map.erase(s[j]);
                    }
                }
                low = map[s[i]]+1;
            }
            else{
                count++;
            }
            map[s[i]] = i;
            mx = max(count,mx);
        }
        return mx;
    }
};