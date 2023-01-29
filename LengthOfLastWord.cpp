// 58. Length of Last Word
// Easy
// 2.6K
// 140
// Companies
// Given a string s consisting of words and spaces, return the length of the last word in the string.

// A word is a maximal 
// substring
//  consisting of non-space characters only.

 

// Example 1:

// Input: s = "Hello World"
// Output: 5
// Explanation: The last word is "World" with length 5.
// Example 2:

// Input: s = "   fly me   to   the moon  "
// Output: 4
// Explanation: The last word is "moon" with length 4.
// Example 3:

// Input: s = "luffy is still joyboy"
// Output: 6
// Explanation: The last word is "joyboy" with length 6.
 

// Constraints:

// 1 <= s.length <= 104
// s consists of only English letters and spaces ' '.
// There will be at least one word in s.
// Accepted
// 1M
// Submissions
// 2.4M
// Acceptance Rate
// 42.0%


class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1;
        int count = 0;
        while(i>=0){
            if(s[i]==' '){
                if(count) return count;
                i--;
                continue;
            }
            i--;
            count++;
        }
        return count;
    }
};

