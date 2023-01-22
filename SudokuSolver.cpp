class Solution {
public:
    bool check(vector<vector<char>>& board,int m,int n,char value){
        //Checking The row
        for(int i=0;i<9;i++){
            if(board[i][n] == value){
                return false;
            }
        }
        for(int i=0;i<9;i++){
            if(board[m][i] == value){
                return false;
            }
        }
        int i = m - m%3;
        int re = i+3;
        int ce = n - n%3 +3;
        for(;i<re;i++){
            int j = n - n%3;
            for(;j<ce;j++){
                if(board[i][j] == value){
                    return false;
                }
            }
        }
        return true;
    }

    bool Sudoku(vector<vector<char>>& board,int row,int col){
        if(col == 9){
            col = 0;
            row += 1;
        }
        if(row == 9){
            return true;
        }
        if(board[row][col]=='.'){
            for(int j=1;j<=9;j++){
                char k = j+48;
                if(check(board,row,col,k)){
                    board[row][col] = k;
                    if(Sudoku(board,row,col+1)){
                        return true;
                    }
                    board[row][col] = '.';
                }      
            }
            //board[row][col] = '.';
            return false;
        }
        return Sudoku(board,row,col+1);
    }

    void solveSudoku(vector<vector<char>>& board) {
        Sudoku(board,0,0);
    }
};