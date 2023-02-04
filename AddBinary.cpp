// 67. Add Binary
// Easy
// 6.7K
// 698
// Companies
// Given two binary strings a and b, return their sum as a binary string.

 

// Example 1:

// Input: a = "11", b = "1"
// Output: "100"
// Example 2:

// Input: a = "1010", b = "1011"
// Output: "10101"
 

// Constraints:

// 1 <= a.length, b.length <= 104
// a and b consist only of '0' or '1' characters.
// Each string does not contain leading zeros except for the zero itself.
// Accepted
// 1M
// Submissions
// 2M
// Acceptance Rate
// 51.5%


class Solution {
public:
    string addBinary(string a, string b) {
        string k = "";
        int l = a.size()-1,m = b.size()-1;
        char carry = '0'; 
        for(;l>=0 && m>=0;l--,m--){
            if(a[l] == '1' && b[m] == '1'){
                k = carry == '1' ? '1'+k : '0'+k;
                carry = '1';
            }
            else if(a[l] == '1' || b[m] == '1'){
                k = carry == '1' ? '0'+k:'1'+k;
                carry = carry == '1' ? '1':'0';
            }
            else{
                k = carry == '1' ? '1'+k : '0'+k;
                carry = '0';
            }
        }
        for(;l>=0;l--){
            if(a[l] == '1'){
                k = carry == '1' ? '0'+k : '1'+k;
                carry = carry == '1' ? '1' : '0';
            }
            else{
                k = carry == '1' ? '1'+k : '0'+k;
                carry = '0';
            }
        }
        for(;m>=0;m--){
            if(b[m] == '1'){
                k = carry == '1' ? '0'+k : '1'+k;
                carry = carry == '1' ? '1' : '0';
            }
            else{
                k = carry == '1' ? '1'+k : '0'+k;
                carry = '0';
            }
        }
        if(carry == '1') k = '1'+k;
        return k;
    }
};