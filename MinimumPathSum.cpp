// 64. Minimum Path Sum
// Medium
// 9.7K
// 125
// Companies
// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

 

// Example 1:


// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
// Example 2:

// Input: grid = [[1,2,3],[4,5,6]]
// Output: 12
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 200
// 0 <= grid[i][j] <= 100
// Accepted
// 859.7K
// Submissions
// 1.4M
// Acceptance Rate
// 61.1%

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size()-1,n = grid[0].size()-1;
        int g[m+1][n+1];
        g[0][0] = grid[0][0];
        for(int i = 1;i<=n;i++){
            g[0][i] = g[0][i-1] + grid[0][i];
        }
        for(int j = 1;j<=m;j++){
            g[j][0] = g[j-1][0] + grid[j][0];
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                g[j][i] = min(g[j-1][i],g[j][i-1]) + grid[j][i];
            }
        }
        return g[m][n];
    }
};