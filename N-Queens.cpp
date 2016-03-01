class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solution;
        vector<string> res (n, string (n, '.'));
        if (n == 0) {
            return solution;
        }
        
        dfs (n, 0, res, solution);
        return solution;
    }
  
    // test if res[row][col] is a valid position to put Q
    bool isValid(int n, int row, int col, vector<string>& res) {
        //check if there has been Q in the same col
        for (int i = 0; i < row; i++) {
            if (res[i][col] == 'Q') {
                return false;
            }
        }
        
        //check if there is Q in diagonal
        int a = row;
        int b = col;
        while (a >= 1 && b >= 1) {
            a--;
            b--;
            if (res[a][b] == 'Q') {
                return false;
            }
        }
        
        //check if there is Q in anti-diagonal
        a = row;
        b = col;
        while (a >= 1 && b < n - 1) {
            a--;
            b++;
            if (res[a][b] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void dfs(int n, int row, vector<string>& res, vector<vector<string>>& solution) {
        if (row == n) {
            solution.push_back(res);
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (isValid(n, row, i, res)) {
                res[row][i] = 'Q';
                dfs(n, row + 1, res, solution);
                res[row][i] = '.';
            }
        }
    }
};
