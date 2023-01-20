// 7. Reverse Integer
// Medium
// 9.5K
// 11.5K
// Companies
// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

// Example 1:

// Input: x = 123
// Output: 321
// Example 2:

// Input: x = -123
// Output: -321
// Example 3:

// Input: x = 120
// Output: 21
 

// Constraints:

// -231 <= x <= 231 - 1

#include<climits>
class Solution {
public:
    long long reverse(long long x) {
        long y = 0;
        while(x){
            int z = x%10;
            x /= 10;
            y  = 10*y + z;
        }
        if(y >= INT_MIN && y<=INT_MAX){
            return y;
        }
        else{
            return 0;
        }
    }
};

