//
//  main.cpp
//  NQueensInChess
//
//  Created by Shujie Hu on 3/1/16.
//  Copyright © 2016 Shujie Hu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void putQueens(int n) {
        vector<vector<string>> res;
        vector<string> r(n, string(n, '.'));
        if (n < 4) {
            cout << "NO valid arrangement for n!" << endl;
            return;
        }
        
        dfs(res, r, n, 0);
        
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < n; j++) {
                cout << res[i][j] << endl;
            }
            cout << endl;
        }
        return;
    }
    
    bool isValid(vector<string> r, int row, int j) {
        if (row == 0) {
            return true;
        }
        for (int pr = 0; pr < row; pr++) {
            if (r[pr][j] == 'Q') {
                return false;
            }
        }
        //check diagonals
        int a = row - 1;
        int b = j - 1;
        while (a >= 0 && b >= 0) {
            if (r[a][b] == 'Q') {
                return false;
            }
            a--;
            b--;
        }
        //check off-diagonal
        a = row - 1;
        b = j + 1;
        while (a >= 0 && b < r.size()) {
            if (r[a][b] == 'Q') {
                return false;
            }
            a--;
            b++;
        }
        return true;
            
    }
            
    void dfs(vector<vector<string>>& res, vector<string> r, int n, int row) {
        if (row == n) {
            res.push_back(r);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isValid(r, row, i)) {
                r[row][i] = 'Q';
                dfs(res, r, n, row + 1);
                r[row][i] = '.';
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol;
    int n;
    cin >> n;
    sol.putQueens(n);

    return 0;
}

