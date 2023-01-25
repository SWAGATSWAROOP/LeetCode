// LeetCode Logo
// Problem List
// Premium
// 0

// avatar
// Description
// Discussion (9)
// Solutions (2K)
// Submissions
// 52. N-Queens II
// Hard
// 3K
// 236
// Companies
// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return the number of distinct solutions to the n-queens puzzle.

 

// Example 1:


// Input: n = 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
// Example 2:

// Input: n = 1
// Output: 1
 

// Constraints:

// 1 <= n <= 9
// Accepted
// 296.5K
// Submissions
// 415.8K
// Acceptance Rate
// 71.3%

class Solution {
public:
    bool check(vector<string> &v,int row,int col,int n){
        for(int i=0;i<n;i++){
            if(v[row][i] == 'Q'){
                return false;
            }
        }

        for(int i=0;i<n;i++){
            if(v[i][col] == 'Q'){
                return false;
            }
        }

        int i = row,j = col;
        while(i >= 0 && j >=0){
            if(v[i--][j--] == 'Q'){
                return false;
            }
        }

        i = row,j = col;
        while(i < n && j < n){
            if(v[i++][j++] == 'Q'){
                return false;
            }
        }

        i = row,j = col;
        while(i < n && j >= 0){
            if(v[i++][j--] == 'Q'){
                return false;
            }
        }

        i = row,j = col;
        while(i >= 0 && j < n){
            if(v[i--][j++] == 'Q'){
                return false;
            }
        }
        return true;
    }

    int solve(vector<string> &v,int row,int n){
        if(row == n){
            return 1;
        }
        int l = 0;
        for(int j=0;j<n;j++){
            if(v[row][j] == '.' && check(v,row,j,n)){
                v[row][j] = 'Q';
                l += solve(v,row+1,n);
                v[row][j] = '.';
            }
        }
        return l;
    }

    int totalNQueens(int n) {
        string k = ".";
        for(int i=1;i<n;i++){
            k += '.';
        }

        vector<string> v1(n,k);
        int l = solve(v1,0,n);
        return l;
    }
};