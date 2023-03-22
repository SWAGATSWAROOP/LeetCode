// 63. Unique Paths II
// Medium
// 6.7K
// 432
// Companies
// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The testcases are generated so that the answer will be less than or equal to 2 * 109.

 

// Example 1:


// Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
// Output: 2
// Explanation: There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right
// Example 2:


// Input: obstacleGrid = [[0,1],[0,0]]
// Output: 1
 

// Constraints:

// m == obstacleGrid.length
// n == obstacleGrid[i].length
// 1 <= m, n <= 100
// obstacleGrid[i][j] is 0 or 1.
// Accepted
// 662.6K
// Submissions
// 1.7M
// Acceptance Rate
// 39.4%

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int n = Grid.size();
        int m = Grid[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(Grid[i][j]) Grid[i][j] = -1;
            }
        }
        for(int i = 0;i<n;i++){
            if(Grid[i][0] == -1)break;
            Grid[i][0] = 1;
        }
        for(int i = 0;i<m;i++){
            if(Grid[0][i] == -1)break;
            Grid[0][i] = 1;
        }
        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                if(Grid[j][i] == -1)continue;
                int l = 0;
                if(Grid[j-1][i] != -1)l += Grid[j-1][i];
                if(Grid[j][i-1] != -1)l += Grid[j][i-1];
                Grid[j][i] = l;
            }
        }
        return Grid[n-1][m-1] == -1 ? 0 : Grid[n-1][m-1];
    }
};

