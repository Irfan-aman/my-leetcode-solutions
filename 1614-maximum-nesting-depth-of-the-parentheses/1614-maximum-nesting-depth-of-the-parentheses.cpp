class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int curr = 0;
        stack<char> st;
        for (char& ch : s) {
            if (ch == '(') {
                st.push('(');
                curr++;
            } else if (ch == ')') {
                st.pop();
                curr--;
            }
            res = max(res, curr);
        }
        return res;
    }
};