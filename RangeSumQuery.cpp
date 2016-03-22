// this is a typical example for getting partial sum in O(1) time
// to achieve that, it is important to get partial sum matrix pSum
// the typical errors I made is the matrix subscript
class NumMatrix {
public:
    vector<vector<int>> pSum;
    NumMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size();
        if (m == 0) {
            return;
        }
        int n = matrix[0].size();
        
        pSum.clear();
        pSum = vector<vector<int>>(m + 1,  vector<int>(n + 1, 0));
        //initializing for the second column
        for (int i = 1; i <= m; i++) {
            pSum[i][1] = pSum[i - 1][1] + matrix[i - 1][0]; 
        }
        
        //initialization for the first row
        for (int i = 1; i <= n; i++) {
            pSum[1][i] = pSum[1][i - 1] + matrix[0][i - 1];
        }
        
        //filling the remaining pSum
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pSum[i][j] = pSum[i - 1][j] + pSum[i][j - 1] - pSum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return pSum[row2 + 1][col2 + 1] - pSum[row1][col2 + 1] - pSum[row2 + 1][col1] + pSum[row1][col1];
    }
};

