class Solution {
public:
    unordered_set<string> st;
    void solve(string& s, int i, string& curr, int& maxLen, int count) {
        if (count < 0)
            return;
        if (i == s.size()) {
            if (count == 0) {
                if (curr.size() > maxLen) {
                    st.clear();
                    maxLen = curr.size();
                }
                if (curr.size() == maxLen)
                    st.insert(curr);
            }
            return;
        }
        if (isalpha(s[i])) {
            curr.push_back(s[i]);
            solve(s, i + 1, curr, maxLen, count);
            curr.pop_back();
            return;
        }
        curr.push_back(s[i]);
        solve(s, i + 1, curr, maxLen, count + (s[i] == '(' ? 1 : -1));
        curr.pop_back();
        solve(s, i + 1, curr, maxLen, count);
    }
    vector<string> removeInvalidParentheses(string s) {
        int maxLen = 0;
        string curr = "";
        st.clear();
        solve(s, 0, curr, maxLen, 0);
        vector<string> res(st.begin(), st.end());
        return res;
    }
};