// LeetCode Logo
// Problem List
// Premium
// 0

// avatar
// Description
// Discussion (108)
// Solutions (12.8K)
// Submissions
// 13. Roman to Integer
// Easy
// 8.9K
// 510
// Companies
// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given a roman numeral, convert it to an integer.

 

// Example 1:

// Input: s = "III"
// Output: 3
// Explanation: III = 3.
// Example 2:

// Input: s = "LVIII"
// Output: 58
// Explanation: L = 50, V= 5, III = 3.
// Example 3:

// Input: s = "MCMXCIV"
// Output: 1994
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

// Constraints:

// 1 <= s.length <= 15
// s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
// It is guaranteed that s is a valid roman numeral in the range [1, 3999].
// Accepted
// 2.4M
// Submissions
// 4.1M
// Acceptance Rate
// 58.2%

class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        int size = s.size();
        for(int i=0;i<size;i++){
            if(s[i] == 'C' && i+1<size && (s[i+1] == 'M' || s[i+1] == 'D')){
                if(s[i+1]=='M'){
                    num += 900;
                }
                else{
                    num += 400;
                }
                i++;
            }
            else if(s[i] == 'X' && i+1<size && (s[i+1] == 'C' || s[i+1] == 'L')){
                if(s[i+1]=='C'){
                    num += 90;
                }
                else{
                    num += 40;
                }
                i++;
            }
            else if(s[i] == 'I' && i+1<size && (s[i+1] == 'X' || s[i+1] == 'V')){
                if(s[i+1]=='X'){
                    num += 9;
                }
                else{
                    num += 4;
                }
                i++;
            }
           else{
               switch(s[i]){
                   case 'M':
                   num += 1000;
                   break;

                   case 'D':
                   num += 500;
                   break; 

                   case 'C':
                   num += 100;
                   break;

                   case 'L':
                   num += 50;
                   break;

                   case 'X':
                   num += 10;
                   break;

                   case 'V':
                   num += 5;
                   break;

                   default:
                   num += 1;
                   break; 
               }
           }
        }
        return num;
    }
};