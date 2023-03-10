// 397. Integer Replacement
// Medium
// 1.1K
// 462
// Companies
// Given a positive integer n, you can apply one of the following operations:

// If n is even, replace n with n / 2.
// If n is odd, replace n with either n + 1 or n - 1.
// Return the minimum number of operations needed for n to become 1.

 

// Example 1:

// Input: n = 8
// Output: 3
// Explanation: 8 -> 4 -> 2 -> 1
// Example 2:

// Input: n = 7
// Output: 4
// Explanation: 7 -> 8 -> 4 -> 2 -> 1
// or 7 -> 6 -> 3 -> 2 -> 1
// Example 3:

// Input: n = 4
// Output: 2
 

// Constraints:

// 1 <= n <= 231 - 1
// Accepted
// 96.3K
// Submissions
// 273.8K
// Acceptance Rate
// 35.2%

//Memotization
class Solution {
public:
    unordered_map<int,int> map;

    int integerReplacement(int n) {
        if(n==1) return 0;
        if(n == INT_MAX) return 32;
        if(!(n & 1)){
            n >>= 1;
            if(map.count(n)>0)return map[n];
            map[n] = 1 + integerReplacement(n);
            return map[n];
        }
        if(map.count(n+1)<=0)map[n+1] = integerReplacement(n+1) + 1;
        if(map.count(n-1)<=0)map[n-1] = integerReplacement(n-1) + 1;
        return min(map[n+1],map[n-1]);
    }
};

//Recursion
class Solution {
public:
    int integerReplacement(int n) {
        if(n==1) return 0;
        if(n == INT_MAX) return 32;
        if(!(n & 1))return 1+integerReplacement(n>>1);
        return 1+min(integerReplacement(n+1),integerReplacement(n-1));
    }
};