// 367. Valid Perfect Square
// Easy
// 3.3K
// 273
// Companies
// Given a positive integer num, return true if num is a perfect square or false otherwise.

// A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.

// You must not use any built-in library function, such as sqrt.

 

// Example 1:

// Input: num = 16
// Output: true
// Explanation: We return true because 4 * 4 = 16 and 4 is an integer.
// Example 2:

// Input: num = 14
// Output: false
// Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.
 

// Constraints:

// 1 <= num <= 231 - 1
// Accepted
// 455.4K
// Submissions
// 1.1M
// Acceptance Rate
// 43.3%


class Solution {
public:
    bool isPerfectSquare(int num) {
    
        int i = 1,j = num;
        while(i<=j){
            long long mid = (1ll*i+1ll*j)/2;
            long long l = 1ll*mid*mid;
            if(l > num) j = mid-1;
            else if(l < num) i = mid+1;
            else return true;
        }
        return false;
    }
};