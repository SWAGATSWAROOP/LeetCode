// 62. Unique Paths
// Medium
// 13.3K
// 377
// Companies
// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

// Example 1:


// Input: m = 3, n = 7
// Output: 28
// Example 2:

// Input: m = 3, n = 2
// Output: 3
// Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Down -> Down
// 2. Down -> Down -> Right
// 3. Down -> Right -> Down
 

// Constraints:

// 1 <= m, n <= 100
// Accepted
// 1.3M
// Submissions
// 2.1M
// Acceptance Rate
// 62.6%

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> v(m,vector<int>(n,1));
        for(int i = 1;i<n;i++){
            for(int j = 1;j<m;j++){
                v[j][i] = v[j-1][i] + v[j][i-1];
            }
        }
        return v[m-1][n-1];
    }
};