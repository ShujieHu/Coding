class Solution {
public:
    int strStr(string haystack, string needle) {
        // the following is for the constructing of the table for the needle
        int m = needle.size();
        if (m <= 0) {
            return 0;
        }
        vector<int> lps(m, 0);
        constructTable(needle, m, lps);
        int n = haystack.size();
        if (n < m) {
            return -1;
        }
        int i = 0;
        int j = 0;
        while (i < n) {
            if (needle[j] == haystack[i]) {
                i++;
                j++;
                if (j == m) {
                    return i - m;
                }
            } else if (j < n && needle[j] != haystack[i]) {
                if (j) {
                    j = lps[j - 1];
                 //   i = i + lps[j - 1];
                } else {
                    i++;
                }
            }
            
        }
        return -1;
    }
    void constructTable(string needle, int m, vector<int>& lps) {
        int len = 0;
        int j = 1;
        lps[0] = 0;
        while (j < m) {
            if (needle[j] == needle[len]) {
                len++;
                lps[j] = len;
                j++;
            } else {
                if (len) {
                    len = lps[len - 1];
                } else {
                    lps[j] = 0;
                    j++;
                }
            }
        }
        
    }
};
