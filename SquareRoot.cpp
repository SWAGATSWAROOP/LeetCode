// 69. Sqrt(x)
// Easy
// 5.7K
// 3.8K
// Companies
// Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

// You must not use any built-in exponent function or operator.

// For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

// Example 1:

// Input: x = 4
// Output: 2
// Explanation: The square root of 4 is 2, so we return 2.
// Example 2:

// Input: x = 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 

// Constraints:

// 0 <= x <= 231 - 1
// Accepted
// 1.3M
// Submissions
// 3.6M
// Acceptance Rate
// 37.2%

#include<cmath>
class Solution {
public:
    int mySqrt(int x) {
        if( x == 0 || x == 1){
            return x;
        }
        long long start = 1;
        long long end = x/2;
        long long ans;
        while(start <= end){
            long long mid = (start+end)/2;
            long long l = mid * mid;
            if(l == x){
                return mid;
            }
            else if(l <= x){
                start = mid+1;
                ans = mid;
            }
            else{
                end = mid - 1;
            }
        }
        return ans;
    }
};