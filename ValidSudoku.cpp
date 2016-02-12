# this question is used to judge if a partially filled sodoku is valid or no#not

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> mst;
        //the following is to check if every row satisfy the rule
        for (int i = 0; i < 9; i++) {
            mst.clear();
            for (int j = 0; j < 9; j++) {
                if (mst.find(board[i][j]) == mst.end()) {
                    mst.insert(board[i][j]);
                } else {
                    if (board[i][j] != '.')
                        return false;
                }
            }
        }
        // the following is to check if every column satisfy the rule
        for (int i = 0; i < 9; i++) {
            mst.clear();
            for (int j = 0; j < 9; j++) {
                if (mst.find(board[j][i]) == mst.end()) {
                    mst.insert(board[j][i]);
                } else {
                    if (board[j][i] != '.')
                        return false;
                }
            }
        }
        // the following is to check if nine small matrices satisfy the rule
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                mst.clear();
                for (int m = 0; m < 3; m++) {
                    for (int n = 0; n < 3; n++) {
                        int x = i * 3 + m;
                        int y = j * 3 + n;
                        if (board[x][y] == '.') {
                            continue;
                        } else if (mst.find(board[x][y]) != mst.end()) {
                            return false;
                        } else {
                            mst.insert(board[x][y]);
                        }
                    }
                }
            }
        }
        return true;
    }
};
