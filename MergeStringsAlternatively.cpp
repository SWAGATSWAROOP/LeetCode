// Easy
// 1.7K
// 28
// Companies
// You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

// Return the merged string.

 

// Example 1:

// Input: word1 = "abc", word2 = "pqr"
// Output: "apbqcr"
// Explanation: The merged string will be merged as so:
// word1:  a   b   c
// word2:    p   q   r
// merged: a p b q c r
// Example 2:

// Input: word1 = "ab", word2 = "pqrs"
// Output: "apbqrs"
// Explanation: Notice that as word2 is longer, "rs" is appended to the end.
// word1:  a   b 
// word2:    p   q   r   s
// merged: a p b q   r   s
// Example 3:

// Input: word1 = "abcd", word2 = "pq"
// Output: "apbqcd"
// Explanation: Notice that as word1 is longer, "cd" is appended to the end.
// word1:  a   b   c   d
// word2:    p   q 
// merged: a p b q c   d
 

// Constraints:

// 1 <= word1.length, word2.length <= 100
// word1 and word2 consist of lowercase English letters.
// Accepted
// 158.1K
// Submissions
// 192.3K
// Acceptance Rate
// 82.2%


class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size(),m = word2.size(),i = 0,j = 0;
        string p = "";
        int count = 0;
        while(i<n && j<m){
            if(count%2)p += word2[j++];
            else p += word1[i++];
            count++;
        }
        if(i<n)p += word1.substr(i);
        if(j<m)p += word2.substr(j);
        return p;
    }
};