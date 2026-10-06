class Solution {
public:
    bool solve(string& s, string& p, int i, int j) {
        if (j == p.size()) {
            return i == s.size();
        }
        bool curr_matches = false;
        if (i < s.size() && (s[i] == p[j] || p[j] == '.'))
            curr_matches = true;
        if (p[j + 1] == '*') {
            bool take = curr_matches && solve(s, p, i + 1, j);
            bool not_take = solve(s, p, i, j + 2);
            return take || not_take;
        } else {
            return curr_matches && solve(s, p, i + 1, j + 1);
        }
    }
    bool isMatch(string s, string p) { return solve(s, p, 0, 0); }
};