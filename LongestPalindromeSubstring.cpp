// 5. Longest Palindromic Substring
// Medium
// 24.2K
// 1.4K
// Companies
// Given a string s, return the longest 
// palindromic
 
// substring
//  in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
 

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters.
// Accepted
// 2.3M
// Submissions
// 7.2M
// Acceptance Rate
// 32.4%

//Solved Using Recursion
class Solution {
public:
    string longest(string s,int size){
        if(size == 1) return s;
        int i = 0,j = s.size()-1;
        while(j>0 && s[0] != s[j]) j--;
        int k = j+1; 
        while(i<j){
            if(s[i]!=s[j]){
                j = k-2;
                while(j>0 && s[0]!=s[j]) j--;
                k = j+1;
                i = 0;
            }
            else{
                i++;
                j--;
            }
        }
        string s1 = s.substr(0,k);
        string s2 = longest(s.substr(1),size-1);
        return s1.size() > s2.size() ? s1:s2;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        return longest(s,n);
    }
};