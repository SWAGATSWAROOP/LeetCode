// 74. Search a 2D Matrix
// Medium
// 11.2K
// 326
// Companies
// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

 

// Example 1:


// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true
// Example 2:


// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -104 <= matrix[i][j], target <= 104
// Accepted
// 1.1M
// Submissions

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        int j = matrix.size()-1;
        int k = matrix[0].size()-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(matrix[mid][k] == target){
                return true;
            }
            else if(matrix[mid][k] > target && matrix[mid][0] <= target){
                int m = 0,n = k;
                while(m<=n){
                    int mid1 = (m+n)/2;
                    if(matrix[mid][mid1] == target){
                        return true;
                    }
                    else if(matrix[mid][mid1] > target){
                        n = mid1-1;
                    }
                    else{
                        m = mid1+1;
                    }
                }
                return false;
            }
            else if(matrix[mid][0] > target){
                j = mid - 1;
            }
            else{
                i = mid+1;
            }
        }
        return false;
    }
};