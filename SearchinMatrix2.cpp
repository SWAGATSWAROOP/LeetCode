// 240. Search a 2D Matrix II
// Medium
// 9.9K
// 165
// Companies
// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.
 

// Example 1:


// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
// Output: true
// Example 2:


// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
// Output: false


//On My own 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0,J = matrix.size()-1,j = J,K = matrix[0].size()-1,l = 0,k = J;
        while(i<j){
            int mid = (i+j)/2;
            if(matrix[mid][K] == target){
                return true;
            }
            if(mid == 0){
                break;
            }
            else if(matrix[mid][K] > target){
                if(matrix[mid-1][K] < target){
                    l = mid;
                    break;
                }
                j = mid-1;
            }
            else{
                 i = mid+1;
            }
        }
        i = 0;
        j = J;
        while(i<j){
            int mid = (i+j)/2;
            if(matrix[mid][0] == target){
                return true;
            }
            if(mid == K){
                break;
            }
            else if(matrix[mid][0] < target){
                if(matrix[mid+1][0] > target){
                    k = mid;
                    break;
                }
                i = mid+1;
            }
            else{
                j = mid - 1;
            }
        }
        for(int i = l;i<=k;i++){
            int o = 0,s = K;
            while(o<=s){
                int mid = (o+s)/2;
                if(matrix[i][mid] == target){
                    return true;
                }
                else if(matrix[i][mid] > target){
                    s = mid-1;
                }
                else{
                    o = mid+1;
                }
            }
        }
        return false;
    }
};

//Saw Faster appproach o(max(m,n))
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0,col = matrix[0].size()-1,rowmx = matrix.size();
        while(row < rowmx && col >=0){
            if(matrix[row][col] < target){
                row++;
            }
            else if(matrix[row][col] > target){
                col--;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
