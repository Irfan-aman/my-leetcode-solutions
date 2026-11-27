class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";
        for (char& ch : address) {
            if (ch == '.')
                res += "[.]";
            else
                res.push_back(ch);
        }
        return res;
    }
};