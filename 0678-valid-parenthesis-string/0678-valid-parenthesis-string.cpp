class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<bool> next(n + 1, false), curr(n + 1, false);
        next[0] = true;
        for (int i = n - 1; i >= 0; i--) {
            fill(curr.begin(), curr.end(), false);
            for (int open = n - 1; open >= 0; open--) {
                if (s[i] == '*') {
                    curr[open] = next[open + 1] || next[open];
                    if (open > 0)
                        curr[open] = curr[open] || next[open - 1];
                } else if (s[i] == '(') {
                    curr[open] = curr[open] || next[open + 1];
                } else if (s[i] == ')' && open > 0) {
                    curr[open] = curr[open] || next[open - 1];
                }
            }
            next.swap(curr);
        }
        return next[0];
    }
};