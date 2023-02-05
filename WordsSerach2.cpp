// LeetCode Logo
// Problem List
// Premium
// 0

// avatar
// Description
// Discussion (41)
// Solutions (2.3K)
// Submissions
// 212. Word Search II
// Hard
// 8.2K
// 381
// Companies
// Given an m x n board of characters and a list of strings words, return all words on the board.

// Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

// Example 1:


// Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
// Output: ["eat","oath"]
// Example 2:


// Input: board = [["a","b"],["c","d"]], words = ["abcb"]
// Output: []
 

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 12
// board[i][j] is a lowercase English letter.
// 1 <= words.length <= 3 * 104
// 1 <= words[i].length <= 10
// words[i] consists of lowercase English letters.
// All the strings of words are unique.
// Accepted
// 541.6K
// Submissions
// 1.5M
// Acceptance Rate
// 36.6%

class Solution {
public:
    bool call(vector<vector<char>>& board,string words,int row,int col,int m,int n){
        if(!words.size()) return true;
        if(row < 0 || col < 0 || row >= m || col >= n || board[row][col]!=words[0]) return false;
        board[row][col] = '+';
        string word = words.substr(1);
        if(call(board,word,row+1,col,m,n) || call(board,word,row-1,col,m,n) || call(board,word,row,col-1,m,n) || call(board,word,row,col+1,m,n)){
            board[row][col] = words[0];
            return true;
        } 
        board[row][col] = words[0];
        return false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(),n = board[0].size(),z = words.size();
        for(auto &word : words){
            reverse(word.begin(),word.end());
        }
        vector<string> v;
        for(int i = 0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int l = 0;l<z;l++){
                if(board[i][j] == words[l][0] && call(board,words[l],i,j,m,n))
                    {
                    reverse(words[l].begin(),words[l].end());
                    v.push_back(words[l]);
                    words[l][0] = '+';
                    }
                }
            }
        }
        return v;
    }
};