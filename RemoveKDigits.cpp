// 402. Remove K Digits
// Medium
// 7.3K
// 310
// Companies
// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

// Example 1:

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
// Example 2:

// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
// Example 3:

// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 

// Constraints:

// 1 <= k <= num.length <= 105
// num consists of only digits.
// num does not have any leading zeros except for the zero itself.
// Accepted
// 304K
// Submissions
// 994.8K
// Acceptance Rate
// 30.6%

class Solution {
public:
    string removeKdigits(string num, int k) {
        string a = "";
        for(auto i:num){
            while(a.length() && a.back()>i && k){
                a.pop_back();
                k--;
            }
            if(a.length() || i!='0')a.push_back(i);
        }
        while(a.length() && k){
            a.pop_back();
            k--;
        }
        return a.empty() ? "0":a;
    }
};
// class Solution {
// public:
//     string removeKdigits(string num, int k) {
//         string res="";
        
//         for(auto c : num){            
// 			while(res.length() && res.back()>c && k){
//                 res.pop_back();
//                 k--;
//             }
//             if(res.length() || c!='0')res.push_back(c);
//         }
//         while(res.length() && k){      
//             k--;
//             res.pop_back();
//         }
//         return res.empty()? "0" : res;         \
//     }
// };