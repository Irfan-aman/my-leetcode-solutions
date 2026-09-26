class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        unordered_map<string, string> mp;
        for (auto& it : knowledge) {
            mp[it[0]] = it[1];
        }
        string res="";
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                int st = i;
                i++;
                while (s[i] != ')')
                    i++;
                int end = i;
                string key = s.substr(st + 1, end - st - 1);
                if (mp.count(key)) {
                    for(int j=0;j<mp[key].size();j++){
                        res.push_back(mp[key][j]);
                    }
                } else {
                    res.push_back('?');
                }
            }else res.push_back(s[i]);
        }
        return res;
    }
};