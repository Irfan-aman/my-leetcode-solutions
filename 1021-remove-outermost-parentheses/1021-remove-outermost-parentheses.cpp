class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<string> primitive;
        int count = 0;
        string str = "";
        for (char& ch : s) {
            str.push_back(ch);
            if (ch == '(')
                count++;
            else
                count--;
            if (count == 0) {
                primitive.push_back(str);
                str = "";
            }
        }
        string res = "";
        for (string& prim : primitive) {
            if (prim.size() == 2)
                continue;
            int len = prim.size();
            res += (prim.substr(1, len - 2));
        }
        return res;
    }
};