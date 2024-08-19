class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j, vector<vector<int>> &visited) {
        // Check boundaries
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return;
        if (board[i][j] != 'O' || visited[i][j]) return;
        
        // Mark this cell as visited
        visited[i][j] = 1;
        
        // Recursively visit all neighboring cells
        dfs(board, i - 1, j, visited); // Up
        dfs(board, i + 1, j, visited); // Down
        dfs(board, i, j - 1, visited); // Left
        dfs(board, i, j + 1, visited); // Right
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        int m = board.size();
        int n = board[0].size();
        
        // Visited array
        vector<vector<int>> visited(m, vector<int>(n, 0));

        // Mark all 'O's on the boundary and connected 'O's as visited
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0, visited);
            if (board[i][n - 1] == 'O') dfs(board, i, n - 1, visited);
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j, visited);
            if (board[m - 1][j] == 'O') dfs(board, m - 1, j, visited);
        }

        // Flip all unvisited 'O's to 'X' and restore visited 'O's
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
