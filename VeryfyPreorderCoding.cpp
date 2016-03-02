// this is to testify if a binary tree is correct or not without previously 
//decoding the string into the binary tree

//core node >= # of '#'

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.size();
        if (n == 0 || preorder[n - 1] != '#') {
            return false;
        }
        int nod = 0;
        int pon = 0;
        int j = 0;
        for (int i = 0; i < n - 1; i++) {
            if (preorder[i] == ',') {
                string t = preorder.substr(j, i - j);
                if (t == "#") {
                    pon++;
                } else {
                    nod++;
                }
                if (nod < pon) {
                    return false;
                }
                j = i + 1;
            }
        }
        
        if (nod == pon) {
            return true;
        }
        return false;
    }
};
