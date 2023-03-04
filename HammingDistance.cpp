// 461. Hamming Distance
// Easy
// 3.5K
// 210
// Companies
// The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

// Given two integers x and y, return the Hamming distance between them.

 

// Example 1:

// Input: x = 1, y = 4
// Output: 2
// Explanation:
// 1   (0 0 0 1)
// 4   (0 1 0 0)
//        ↑   ↑
// The above arrows point to positions where the corresponding bits are different.
// Example 2:

// Input: x = 3, y = 1
// Output: 1
 

// Constraints:

// 0 <= x, y <= 231 - 1
// Accepted
// 515.7K
// Submissions
// 687.7K
// Acceptance Rate
// 75.0

class Solution {
public:
    int hammingDistance(int x, int y) {
        int l = x ^ y,count = 0;
        while(l){
            l = l & (l-1);
            count += 1;
        } 
        return count;
    }
};