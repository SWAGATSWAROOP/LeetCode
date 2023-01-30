// 54. Spiral Matrix
// Medium
// 10.3K
// 994
// Companies
// Given an m x n matrix, return all elements of the matrix in spiral order.

 

// Example 1:


// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:


// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100
// Accepted
// 952.9K
// Submissions
// 2.1M
// Acceptance Rate
// 44.4%

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int str = 0,stc=0,endr = matrix.size()-1,endc = matrix[0].size()-1;
        int count = (endr+1)*(endc+1);
        vector<int> v;
        while(count){
            int i = str,j = stc;
            for(;j<=endc && count;j++){
                v.push_back(matrix[i][j]);
                count--;
            }
            j = endc;
            i++;
            for(;i<=endr && count;i++){
                v.push_back(matrix[i][j]);
                count--;
            }
            i = endr;
            j--;
            for(;j>=stc && count;j--){
                v.push_back(matrix[i][j]);
                count--;
            }
            i--;
            j = stc;
            for(;i>str && count;i--){
                v.push_back(matrix[i][j]);
                count--;
            }
            stc++;
            str++;
            endr--;
            endc--;
        }
    return v;
    }
};