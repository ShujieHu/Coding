# this is to judge if a string containing only parenthesis are valid parenthesis
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 != 0) {
            return false;
        }
        if (n == 0) {
            return true;
        }
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < n; i++) {
            if (s[i] == ')' && st.top() =='(') {
                st.pop();
            } else if (s[i] == '}' && st.top() == '{') {
                st.pop();
            } else if (s[i] == ']' && st.top() == '[') {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};
