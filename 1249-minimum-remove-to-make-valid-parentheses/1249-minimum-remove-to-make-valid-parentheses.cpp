class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        string temp = "";
        int open = 0;
        for (int i = 0; i < n; i++) {
            if (isalpha(s[i])) {
                temp.push_back(s[i]);
            } else if (s[i] == '(') {
                open++;
                temp.push_back('(');
            } else if (open > 0) {
                open--;
                temp.push_back(')');
            }
        }
        string res = "";
        if (open == 0)
            return temp;
        for (int i = temp.size() - 1; i >= 0; i--) {
            if (temp[i] == '(' && open > 0) {
                open--;
            } else {
                res.push_back(temp[i]);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};