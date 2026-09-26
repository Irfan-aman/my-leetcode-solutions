class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        unordered_map<string, string> mp;
        for (auto& it : knowledge) {
            mp[it[0]] = it[1];
        }
        string res = "";
        int i = 0;
        while (i < n) {
            if (s[i] == '(') {
                int j = s.find(')', i + 1);
                string key = s.substr(i + 1, j - i - 1);
                res += mp.count(key) ? mp[key] : "?";
                i = j;
            } else {
                res.push_back(s[i]);
            }
            i++;
        }
        return res;
    }
};