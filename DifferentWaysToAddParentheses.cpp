//typical example of given a tring containing numbers and +,-,* only, calculate the possible results by adding parentheses
//copy right reserved by Shujie Hu

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int>res;
        bool purenumber = true;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] > '9' || input[i] < '0') {
                purenumber = false;
                vector<int> L = diffWaysToCompute(input.substr(0, i));
                vector<int> R = diffWaysToCompute(input.substr(i + 1, input.size() - i - 1));
                for (auto l : L) {
                    for (auto r : R) {
                        if (input[i] == '+') {
                            res.push_back(l + r);
                        } else if (input[i] == '-') {
                            res.push_back(l - r);
                        } else {
                            res.push_back(l * r);
                        }
                    }
                }
            }
        }
        
        if (purenumber) {
            //pure number just store the whole number into res
            res.push_back(stoi(input));
        }
        return res;
    }
};
