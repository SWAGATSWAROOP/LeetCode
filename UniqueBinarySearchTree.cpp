// 96. Unique Binary Search Trees
// Medium
// 9K
// 355
// Companies
// Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

 

// Example 1:


// Input: n = 3
// Output: 5
// Example 2:

// Input: n = 1
// Output: 1
 

// Constraints:

// 1 <= n <= 19
// Accepted
// 564.9K
// Submissions
// 946.5K
// Acceptance Rate
// 59.7%

class Solution {
public:
    int numTrees(int n) {
        if(n<=2)return n;
        int arr[n+1];
        arr[0] = 1;
        arr[1] = 1;
        arr[2] = 2;
        for(int i = 3;i<=n;i++){
            arr[i] = 0;
            for(int j = 1;j<=i;j++){
                arr[i] += arr[j-1]*arr[i-j];
            }
        }
        return arr[n];
    }
};