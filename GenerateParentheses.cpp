class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string tr = "";
        if (n == 0) {
            return res;
        }
        dfs(n, 0, 0, res, tr);
        return res;
    }
    void dfs(int n, int l, int r, vector<string>& res, string& tr) {
        if (l > n) {
            return;
        }
        if (l == n && r == n) {
            res.push_back(tr);
        } else {
            tr = tr + "(";
            dfs(n, l + 1, r, res, tr);
            tr.pop_back(); 
            if (l > r) {
                tr.push_back(')'); 
                dfs (n, l, r + 1, res, tr);
                tr.pop_back();
            }
        }
    }
};
