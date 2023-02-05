// 79. Word Search
// Medium
// 12.7K
// 513
// Companies
// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

// Example 1:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true
// Example 2:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true
// Example 3:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false
 

// Constraints:

// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board and word consists of only lowercase and uppercase English letters.
 

// Follow up: Could you use search pruning to make your solution faster with a larger board?

// Accepted
// 1.2M
// Submissions
// 3M
// Acceptance Rate
// 40.2%


class Solution {
public:
    bool call(vector<vector<char>>& board, string word,int row,int col,int m,int n){
        if(!word.size()) return true;
        if(row < 0 || col < 0 || row >= m || col >= n || word[0]!=board[row][col])return false;
        board[row][col] = '+';
        string l = word.substr(1);
        if(call(board,l,row+1,col,m,n) || call(board,l,row-1,col,m,n) || call(board,l,row,col-1,m,n) || call(board,l,row,col+1,m,n)) return true;
        board[row][col] = word[0];
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(),n = board[0].size();
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j] == word[0] && call(board,word,i,j,m,n)){
                    return true;
                }
            }
        }
        return false;
    }
};