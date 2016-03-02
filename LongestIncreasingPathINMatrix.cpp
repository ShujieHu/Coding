class Solution {
public:
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {1, -1, 0, 0};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return 0;
        }
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int i = 0; i< m; i++) {
            for (int j = 0; j < n; j++) {
                //gonna combine dp with dfs
                if (dp[i][j] == -1) {
                    //never visited the matrix before
                    dfs(matrix, dp, i, j);
                }
            }
        }
        
        int res = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
    
    void dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int row, int col) {
        
        for (int i = 0; i < 4; i++) {
            int x = row + dx[i];
            int y = col + dy[i];
            if (x >= 0 && y >= 0 && x < matrix.size() && y < matrix[0].size() && matrix[x][y] > matrix[row][col]) {
                if (dp[x][y] == -1) {
                    dfs(matrix, dp, x, y);
                }
                dp[row][col] = max(dp[x][y] + 1, dp[row][col]);
            }
            //the biggest value among its neighborhood
            dp[row][col] = max(dp[row][col], 1);
        }
    }
};
