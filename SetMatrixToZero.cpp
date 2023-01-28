// 73. Set Matrix Zeroes
// Medium
// 10.4K
// 595
// Companies
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.

 

// Example 1:


// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]
// Example 2:


// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

// Constraints:

// m == matrix.length
// n == matrix[0].length
// 1 <= m, n <= 200
// -231 <= matrix[i][j] <= 231 - 1
 

// Follow up:

// A straightforward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?
// Accepted
// 916.2K
// Submissions
// 1.8M
// Acceptance Rate
// 50.7%

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        queue<int> row;
        queue<int> col;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!matrix[i][j]){
                    row.push(i);
                    col.push(j);
                }
            }
        }
        while(!row.empty() && !col.empty()){
            for(int i=0;i<m;i++){
                matrix[i][col.front()] = 0;
            }
            for(int j=0;j<n;j++){
                matrix[row.front()][j] = 0;
            }
            row.pop();
            col.pop();
        }
    }
};