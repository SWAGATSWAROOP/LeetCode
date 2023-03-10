// 1876. Substrings of Size Three with Distinct Characters
// Easy
// 1K
// 28
// Companies
// A string is good if there are no repeated characters.

// Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.

// Note that if there are multiple occurrences of the same substring, every occurrence should be counted.

// A substring is a contiguous sequence of characters in a string.

 

// Example 1:

// Input: s = "xyzzaz"
// Output: 1
// Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz". 
// The only good substring of length 3 is "xyz".
// Example 2:

// Input: s = "aababcabc"
// Output: 4
// Explanation: There are 7 substrings of size 3: "aab", "aba", "bab", "abc", "bca", "cab", and "abc".
// The good substrings are "abc", "bca", "cab", and "abc".
 

// Constraints:

// 1 <= s.length <= 100
// s​​​​​​ consists of lowercase English letters.
// Accepted
// 71.4K
// Submissions
// 100.7K
// Acceptance Rate
// 71.0%

class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size(),count = 0;
        for(int i = 0,j = 2;j<n;j++,i++){
            if(s[i] == s[j]) continue;
            else if(s[i]!= s[i+1] && s[i+1]!= s[j]) count++;
        }
        return count;
    }
};

//for any value of K here it is 3
class Solution {
public:
    int countGoodSubstrings(string s) {
        int ans=0;
        int i=0,j=0,n=s.length(),k=3;
        unordered_map<char,int>mp;
        while(j<n){
            mp[s[j]]++;
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                if(mp.size()==k){
                    ans++;
                }
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};