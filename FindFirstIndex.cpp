// 28. Find the Index of the First Occurrence in a String
// Medium
// 1.4K
// 99
// Companies
// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

// Example 1:

// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.
// Example 2:

// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

// Constraints:

// 1 <= haystack.length, needle.length <= 104
// haystack and needle consist of only lowercase English characters.
// Accepted
// 1.5M
// Submissions
// 4M
// Acceptance Rate
// 37.9%

class Solution {
public:
    int strStr(string haystack, string needle) {
        int j = 0;
        int c = -1;
        bool m = false;
        int o = 0;
        int i=0;
        while(i<haystack.size()){
            if(j!=0 && needle[0] == haystack[i] &&!o){
                o = i;
            }
            if(haystack[i]==needle[j]){
                if(j==0){
                    c = i;
                }
                if(j==needle.size()-1){
                    return c;
                }
                j++;
                i++;
            }
            else if(o){
                i = o;
                j = 0;
                o = 0;
            }
            else{
                j=0;
                i++;
            }
        }
        return -1;
    }
};