// 409. Longest Palindrome
// Easy
// 4.4K
// 264
// Companies
// Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

// Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

 

// Example 1:

// Input: s = "abccccdd"
// Output: 7
// Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
// Example 2:

// Input: s = "a"
// Output: 1
// Explanation: The longest palindrome that can be built is "a", whose length is 1.
 

// Constraints:

// 1 <= s.length <= 2000
// s consists of lowercase and/or uppercase English letters only.
// Accepted
// 473.5K
// Submissions
// 871.2K
// Acceptance Rate
// 54.4%

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> map;
        int n = s.size();
        for(int i=0;i<n;i++){
            map[s[i]]++;
        }
        int counte = 0,counto = 0;
        for(auto i:map){
            if(i.second%2==0) counte+= i.second;
            else{
                int l = i.second;
                l -= l%2;
                if(i.second > 1) counte += l;
                counto += i.second; 
            }
        }
        if(counto) counte+=1;
        return counte;
    }
};