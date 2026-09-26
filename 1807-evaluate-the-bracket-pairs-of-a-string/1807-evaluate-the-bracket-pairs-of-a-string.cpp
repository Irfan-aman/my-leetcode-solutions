class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto& it : knowledge) {
            mp[it[0]] = it[1];
        }
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '(')
                continue;
            int st = i;
            int end = s.find(')', i);
            string key = s.substr(st + 1, end - st - 1);
            string value = mp.count(key) ? mp[key] : "?";
            s.replace(st, end - st + 1, value);
            i = st + value.size() - 1;
        }
        return s;
    }
};