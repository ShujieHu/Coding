# this is a typical brain teasing problem
# the answer is simple: only squares are the ideal solution (odd number of factors)
class Solution {
public:
    int bulbSwitch(int n) {
        //by analysis only need to find the x^2 where x^2 <= n
        int res = 0;
        for (int i = 1; i * i <= n; i++) {
            res++;
        }
        return res;
    }
};
