// 29. Divide Two Integers
// Medium
// 3.9K
// 12.6K
// Companies
// Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

// The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

// Return the quotient after dividing dividend by divisor.

// Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

 

// Example 1:

// Input: dividend = 10, divisor = 3
// Output: 3
// Explanation: 10/3 = 3.33333.. which is truncated to 3.
// Example 2:

// Input: dividend = 7, divisor = -3
// Output: -2
// Explanation: 7/-3 = -2.33333.. which is truncated to -2.
 

// Constraints:

// -231 <= dividend, divisor <= 231 - 1
// divisor != 0
// Accepted
// 575.1K
// Submissions
// 3.3M
// Acceptance Rate
// 17.2%
//My Technique
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == INT_MIN && divisor == 1) return INT_MIN; 
        int minus = 1;
        if(divisor < 0 ^ dividend < 0){
            minus = -1;
        }
        int res = 0;
        long int div = abs(divisor);
        long int  divi = abs(dividend);
        while(div<=divi){
            long int temp = 1,mul = div;
            while(divi-mul >= mul){
                mul = mul << 1;
                temp = temp << 1;
            }
            res += temp;
            divi -= mul;
        }
        return minus*res;
    }
};


//Others
// class Solution {
// public:
//     int divide(int dividend, int divisor) {
        
//         //Handling corner cases
//         if(dividend==INT_MIN && divisor==-1) return INT_MAX;
//         if(dividend==INT_MIN && divisor==1) return INT_MIN;

        
//         //Converting divisors and dividend to their positive values
//         long int dd = abs(dividend), dv = abs(divisor);
        
//         //Result Variables
//         int res=0;
//         while(dv<=dd) {
//             long int mul=dv, tmp=1;
//             while(mul<=dd-mul) {
//                 mul+=mul;
//                 tmp+=tmp;
//             }
//             res+=tmp;
//             dd-=mul;
//         }
        
//         //If either of dividend or divisor is negative our result will be negative
//         if((dividend<0&&divisor>0) || (dividend>0&&divisor<0)) return -res;
        
//         return res;
        
//     }
// };


// class Solution {
// public:
//     int divide(int dividend, int divisor)
//     {
//         if (dividend == INT_MIN && divisor == -1)
//             return INT_MAX;
//         if (dividend == INT_MIN && divisor == 1)
//             return INT_MIN;

//         long int dd = abs(dividend), dv = abs(divisor);

//         int res = 0;
//         while (dv <= dd) {
//             long int mul = dv, tmp = 1;
//             while (mul <= dd - mul) {
//                 mul = mul << 1;
//                 tmp = tmp << 1;
//             }
//             res += tmp;
//             dd -= mul;
//         }

//         if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
//             return -res;

//         return res;
//     }
// };