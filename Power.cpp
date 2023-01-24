// 50. Pow(x, n)
// Medium
// 6.5K
// 6.9K
// Companies
// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

// Example 1:

// Input: x = 2.00000, n = 10
// Output: 1024.00000
// Example 2:

// Input: x = 2.10000, n = 3
// Output: 9.26100
// Example 3:

// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

// Constraints:

// -100.0 < x < 100.0
// -231 <= n <= 231-1
// n is an integer.
// -104 <= xn <= 104
// Accepted
// 1.1M
// Submissions
// 3.4M
// Acceptance Rate
// 32.9%

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return x;
        }
        if(n%2==0){
            int k = abs(n);
            double l = myPow(x,k/2);
            if(n < 0){
                return 1/(l*l);
            }
            return l*l;
        }
        else{
            int k = abs(n);
            double l = myPow(x,(k-1)/2);
            if(n < 0){
                return 1/(x*l*l);
            }
            return x*l*l;
        }
    }
};