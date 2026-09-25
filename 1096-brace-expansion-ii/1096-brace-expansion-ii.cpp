class Solution {
public:
    int n;
    string s;
    int idx = 0;
    set<string> getUnit() {
        set<string> result;
        if (s[idx] == '{') {
            idx++;
            result = performUnion();
            idx++;
        } else {
            result = {string(1, s[idx])};
            idx++;
        }
        return result;
    }
    set<string> performConcat() {
        set<string> result = {""};
        while (idx < n && (s[idx] == '{' || isalnum(s[idx]))) {
            set<string> temp = getUnit();
            set<string> concat;
            for (const string& left : result) {
                for (const string& right : temp) {
                    concat.insert(left + right);
                }
            }
            result = concat;
        }
        return result;
    }
    set<string> performUnion() {
        set<string> result;
        while (true) {
            set<string> temp = performConcat();
            result.insert(temp.begin(), temp.end());
            if (idx < n && s[idx] == ',') {
                idx++;
            } else {
                break;
            }
        }
        return result;
    }
    vector<string> braceExpansionII(string expression) {
        n = expression.size();
        s = expression;
        set<string> temp = performUnion();
        vector<string> res(temp.begin(), temp.end());
        return res;
    }
};