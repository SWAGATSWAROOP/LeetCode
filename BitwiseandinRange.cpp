// 201. Bitwise AND of Numbers Range
// Medium
// 2.7K
// 196
// Companies
// Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

 

// Example 1:

// Input: left = 5, right = 7
// Output: 4
// Example 2:

// Input: left = 0, right = 0
// Output: 0
// Example 3:

// Input: left = 1, right = 2147483647
// Output: 0
 

// Constraints:

// 0 <= left <= right <= 231 - 1
// Accepted
// 237.1K
// Submissions
// 558.2K
// Acceptance Rate
// 42.5%

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(right - left < 2) return left & right;
        int a = 0x10000000,count1 = 32,count2 = 32;
        while(!(a & left) && a){
            count1--;
            a = a >> 1;
        }
        a = 0x10000000;
        while(!(a & right) && a){
            count2--;
            a = a >> 1;
        }
        if(count1 != count2) return 0;
        for(int i = left+1;i<=right;i++) left &= i;
        return left;
    }
};