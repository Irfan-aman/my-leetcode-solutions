class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> start(26, -1), end(26);
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if (start[idx] == -1) {
                start[idx] = i;
            }
            end[idx] = i;
        }
        vector<bool> isValid(26, true);
        for (int c = 0; c < 26; c++) {
            if (start[c] == -1)
                continue;
            for (int i = start[c]; i <= end[c]; i++) {
                if (start[s[i] - 'a'] < start[c]) {
                    isValid[c] = false;
                    break;
                }
                end[c] = max(end[c], end[s[i] - 'a']);
            }
        }
        vector<string> res;
        int lastTakenStart = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            int idx = s[i] - 'a';
            if (!isValid[idx])
                continue;
            if (i == start[idx] && end[idx] < lastTakenStart) {
                res.push_back(s.substr(i, end[idx] - i + 1));
                lastTakenStart = i;
            }
        }
        return res;
    }
};