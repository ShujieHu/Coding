class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        if (n < 0) {
            return res;
        }
        res.push_back(0);
        getResult(n, res);
        return res;
    }
    void getResult(int n, vector<int>& res) {
        if (n == 0) {
            return;
        }
        getResult(n - 1, res);
        int len = res.size();
        for (int j = len - 1; j >= 0; j--) {
            res.push_back(res[j] | (1 << (n - 1)));
        }
    }
};
