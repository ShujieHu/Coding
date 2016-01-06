ass Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        if (m == 0) {
            return 0;
        }
        
        int n = dungeon[0].size();
        vector<vector<int>> dp (m, vector<int> (n, 1));
        // creating dp and initialize dp[m - 1][n - 1] with the minimun blood
        // if dungeon[m - 1][n - 1] ispositive, then dp[m-1][n-1] is 1;
        //if negative, it is 1 - dungeon[m - 1][n - 1]
        dp[m - 1][n - 1] = max (1, 1 - dungeon[m - 1][n - 1]);
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (j == n - 1 && i < m - 1) {
                    dp[i][j] = max(dp[i + 1][j] - dungeon[i][j], 1);
                } else if (i == m - 1 && j < n - 1) {
                    dp[i][j] = max(dp[i][j + 1] - dungeon[i][j], 1);
                } else if (i < m - 1 && j < n - 1) {
                    // general case, pick up the smallest dp values and deduct it by corresponding dungeon value
                    // then compare this value with 1
                    dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 1);
                }
            }
        }
        
        return dp[0][0];
    }
};
