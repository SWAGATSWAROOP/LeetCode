// 342. Power of Four
// Easy
// 2.9K
// 334
// Companies
// Given an integer n, return true if it is a power of four. Otherwise, return false.

// An integer n is a power of four, if there exists an integer x such that n == 4x.

 

// Example 1:

// Input: n = 16
// Output: true
// Example 2:

// Input: n = 5
// Output: false
// Example 3:

// Input: n = 1
// Output: true
 

// Constraints:

// -231 <= n <= 231 - 1
 

// Follow up: Could you solve it without loops/recursion?
// Accepted
// 442.5K
// Submissions
// 960.9K
// Acceptance Rate
// 46.1%

//Naive Solution
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(!n) return false;
        int count = -1,noofone = 0;
        while(n){
            count+=1;
            if(n & 1){
                if(count & 1 || noofone == 1) return false;
                noofone++;
            }
            n = n >> 1; 
        }
        return true;
    }
};

//Second Apporach Not Optimesied that much
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(!n || n == INT_MAX || n == INT_MIN) return false;
        int count = n & (n-1) ? 0 : 1;
        if(!count) return false;
        while(n){
            if(n & 1) return true;
            n = n >> 2;
        }
        return false;        
    }
};

//Fastest Approach
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == INT_MAX || n== INT_MIN) return false;
        return !(n & (n-1)) && (n & 0x55555555);
    }
};

//Little Optimised
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n>0 && !(n & (n-1)) && (n & 0x55555555);
    }
};