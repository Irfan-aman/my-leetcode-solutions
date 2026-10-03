class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int oc = 0, cc = 0; // oc=open count , cc=close count
        int ans = 0;
        for (char& ch : s) {
            if (ch == '(')
                oc++;
            else
                cc++;
            if (oc == cc)
                ans = max(ans, oc + cc);
            else if (cc > oc) {
                oc = 0;
                cc = 0;
            }
        }
        oc = 0;
        cc = 0;
        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];
            if (ch == '(')
                oc++;
            else
                cc++;
            if (oc == cc)
                ans = max(ans, oc + cc);
            else if (oc > cc) {
                oc = 0;
                cc = 0;
            }
        }
        return ans;
    }
};