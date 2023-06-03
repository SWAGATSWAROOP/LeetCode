// 931. Minimum Falling Path Sum
// Medium
// 4.8K
// 123
// Companies
// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

// A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

// Example 1:


// Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
// Output: 13
// Explanation: There are two falling paths with a minimum sum as shown.
// Example 2:


// Input: matrix = [[-19,57],[-40,-5]]
// Output: -59
// Explanation: The falling path with a minimum sum is shown.
 

// Constraints:

// n == matrix.length == matrix[i].length
// 1 <= n <= 100
// -100 <= matrix[i][j] <= 100
// Accepted
// 249.5K
// Submissions
// 360.9K
// Acceptance Rate
// 69.1%

const static auto initialize = [] { std::ios::sync_with_stdio(false); 
std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size()-1;
        if(!n)return matrix[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                if(j == 0)matrix[i][j] += min(matrix[i-1][j],matrix[i-1][j+1]);
                else if(j == n)matrix[i][j] += min(matrix[i-1][j-1],matrix[i-1][j]);
                else matrix[i][j] += min(matrix[i-1][j-1],min(matrix[i-1][j],matrix[i-1][j+1])); 
            }
        }
        int mn = INT_MAX;
        for(int j=0;j<=n;j++){
            if(j == 0)matrix[n][j] += min(matrix[n-1][j],matrix[n-1][j+1]);
                else if(j == n)matrix[n][j] += min(matrix[n-1][j-1],matrix[n-1][j]);
                else matrix[n][j] += min(matrix[n-1][j-1],min(matrix[n-1][j],matrix[n-1][j+1])); 
                mn = min(mn,matrix[n][j]);
        }
        return mn;
    }
};