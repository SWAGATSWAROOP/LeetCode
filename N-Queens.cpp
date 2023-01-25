// LeetCode Logo
// Problem List
// Premium
// 0

// avatar
// Description
// Discussion (14)
// Solutions (3.6K)
// Submissions
// 51. N-Queens
// Hard
// 9.2K
// 205
// Companies
// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

// Example 1:


// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
// Example 2:

// Input: n = 1
// Output: [["Q"]]
 

// Constraints:

// 1 <= n <= 9
// Accepted
// 509.4K
// Submissions
// 800.1K
// Acceptance Rate
// 63.7%

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

    void solve(vector<vector<string>>&v1,vector<string> &v,int row,int n){
        if(row == n){
            v1.push_back(v);
            return;
        }
        for(int j=0;j<n;j++){
            if(v[row][j] == '.' && check(v,row,j,n)){
                v[row][j] = 'Q';
                solve(v1,v,row+1,n);
                v[row][j] = '.';
            }
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> v;
        string k = ".";
        for(int i=1;i<n;i++){
            k += '.';
        }
        vector<string> v1(n,k);
        solve(v,v1,0,n);
        return v;
    }
};