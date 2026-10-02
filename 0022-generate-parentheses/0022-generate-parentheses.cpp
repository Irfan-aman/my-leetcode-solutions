class Solution {
public:
    vector<string> allParentheses;
    void solve(int n, int oc, int cc, string str) {
        if (cc == n) allParentheses.push_back(str);
        if (oc < n) solve(n, oc + 1, cc, str + '(');
        if (cc < oc) solve(n, oc, cc + 1, str + ')');
    }
    vector<string> generateParenthesis(int n) {
        solve(n, 0, 0, "");
        return allParentheses;
    }
};