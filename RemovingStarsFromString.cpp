// Medium
// 2K
// 137
// Companies
// You are given a string s, which contains stars *.

// In one operation, you can:

// Choose a star in s.
// Remove the closest non-star character to its left, as well as remove the star itself.
// Return the string after all stars have been removed.

// Note:

// The input will be generated such that the operation is always possible.
// It can be shown that the resulting string will always be unique.
 

// Example 1:

// Input: s = "leet**cod*e"
// Output: "lecoe"
// Explanation: Performing the removals from left to right:
// - The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
// - The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
// - The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
// There are no more stars, so we return "lecoe".
// Example 2:

// Input: s = "erase*****"
// Output: ""
// Explanation: The entire string is removed, so we return an empty string.
 

// Constraints:

// 1 <= s.length <= 105
// s consists of lowercase English letters and stars *.
// The operation above can be performed on s.
// Accepted
// 122.3K
// Submissions
// 168.8K
// Acceptance Rate
// 72.4%

class Solution {
public:
    string removeStars(string s) {
        string l = "";
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='*')l.pop_back();
            else l.push_back(s[i]);
        }
        return l;
    }
};

//More Optimized Solution
class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        int j = 0;
        for(int i=0;i<n;i++){
            if(s[i]!='*')s[j++] = s[i];
            else j--;
        }
        return s.substr(0,j);
    }
};