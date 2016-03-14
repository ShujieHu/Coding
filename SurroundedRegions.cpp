class Solution {
public:
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m <= 2) {
            return;
        }
        int n = board[0].size();
        if (n <= 2) {
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                dfs(board, 0, i);
            }
            if (board[m - 1][i] == 'O') {
                dfs(board, m - 1, i);
            }
        }
        
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if (board[i][n - 1] == 'O') {
                dfs(board, i, n - 1);
            }
        }
        
        //after dfs the matrix board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '*') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, int row, int col) {
        int m = board.size();
        int n = board[0].size();
        if (row < 0 || col < 0 || row >= m || col >= n || board[row][col] == 'X' || board[row][col] == '*') {
            return;
        }
        if (board[row][col] == 'O')
            board[row][col] = '*';
        for (int i = 0; i < 4; i++) {
            int x = row + dx[i];
            int y = col + dy[i];
            dfs(board, x, y);
        }
    }
