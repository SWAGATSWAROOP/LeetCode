// 38. Count and Say
// Medium
// 3K
// 6.4K
// Companies
// The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

// countAndSay(1) = "1"
// countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
// To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.

// For example, the saying and conversion for digit string "3322251":


// Given a positive integer n, return the nth term of the count-and-say sequence.

 

// Example 1:

// Input: n = 1
// Output: "1"
// Explanation: This is the base case.
// Example 2:

// Input: n = 4
// Output: "1211"
// Explanation:
// countAndSay(1) = "1"
// countAndSay(2) = say "1" = one 1 = "11"
// countAndSay(3) = say "11" = two 1's = "21"
// countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
 

// Constraints:

// 1 <= n <= 30
// Accepted
// 771.5K
// Submissions
// 1.5M
// Acceptance Rate
// 52.0%

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)return "1";
        string m = countAndSay(n-1);
        int o = m.size()-1;
        int count = 1;
        string k = "";
        for(int i = 0;i<o;i++){
            if(m[i]==m[i+1])count++;
            else{
                k += count+48;
                k = k + m[i];
                count = 1;
            }
        }
        if(count > 1) k += count + 48;
        else k += '1'; 
        k += m[o];
        return k;
    }
};