class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int n = s.size();
        string res = "";
        for (auto& ch : s) {
            if (ch == '(') {
                st.push(res.size());
            } else if (ch == ')') {
                reverse(res.begin() + st.top(), res.end());
                st.pop();
            } else {
                res.push_back(ch);
            }
        }
        return res;
    }
};