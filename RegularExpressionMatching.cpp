// '.' matches any single char
// '*' matches 0 to more of its proceeding element
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>>dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
       
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                //match s 0 to i - 1 with string p 0 to j - 1
                if (p[j - 1] != '*' && p[j - 1] != '.') {
                    if (i > 0) {
                        dp[i][j] = (p[j - 1] == s[i - 1] && dp[i - 1][j - 1]);
                    }
                } else if (p[j - 1] == '.') {
                    if (i > 0) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                } else {
                    //p[j - 1] matches 0 s[0-i - 1]
                    if (dp[i][j - 2]) {
                        dp[i][j] = true;
                    } else {
                        for (int k = 1; k <= i; k++) {
                            if (j >= 2 && (p[j - 2] == s[i - k] || p[j - 2] == '.') ) {
                                if (dp[i - k][j - 2]) {
                                    dp[i][j] = true;
                                    break;
                                }
                            } else {
                                break;
                            }
                        }
                    }
                }
            }
        }
        return dp[m][n];
    }
};
