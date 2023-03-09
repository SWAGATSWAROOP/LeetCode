// 693. Binary Number with Alternating Bits
// Easy
// 1.2K
// 107
// Companies
// Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

 

// Example 1:

// Input: n = 5
// Output: true
// Explanation: The binary representation of 5 is: 101
// Example 2:

// Input: n = 7
// Output: false
// Explanation: The binary representation of 7 is: 111.
// Example 3:

// Input: n = 11
// Output: false
// Explanation: The binary representation of 11 is: 1011.
 

// Constraints:

// 1 <= n <= 231 - 1
// Accepted
// 110.3K
// Submissions
// 179.2K
// Acceptance Rate
// 61.5%

class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long int a = 1,b = 2;
        if(!(n & 1)){
            a = 2;
            b = 1;
        } 
        while(a <= n){
            if(!(a & n) || (b & n)) return false;
            cout<<(a & n)<<" "<<(b & n)<<endl;
            a <<= 2;
            b <<= 2; 
        }
        if((a>>1) & n) return false;
        return true;
    }
};