class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int> lastOcc(26, 0);
        for (int i = 0; i < n; i++) {
            lastOcc[s[i] - 'a'] = i;
        }
        vector<bool> vis(26, false);
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (vis[s[i] - 'a'])
                continue;
            while (!ans.empty() && ans.back() > s[i] &&
                   lastOcc[ans.back() - 'a'] > i) {
                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            vis[s[i] - 'a'] = true;
        }
        return ans;
    }
};