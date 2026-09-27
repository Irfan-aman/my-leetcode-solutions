class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int n = s.size();
        vector<int> pair(n);
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (isalpha(ch))
                continue;
            if (ch == '(') {
                st.push(i);
            } else if (ch == ')') {
                int j = st.top();
                st.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }
        bool leftToRight = true;
        string res = "";
        int i = 0;
        while (i < n) {
            if (s[i] == '(' || s[i] == ')') {
                leftToRight = !leftToRight;
                i = pair[i];
                if (leftToRight)
                    i++;
                else
                    i--;
                continue;
            }

            res += s[i];

            if (leftToRight) {
                i++;
            } else if (!leftToRight) {
                i--;
            }
        }
        return res;
    }
};