class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        vector<int> mp(26, 0);
        int i = 0;
        int ans = 0;
        for (int j = 0; j < n; j++) {
            mp[s[j] - 'a']++;
            while (mp[s[j] - 'a'] > 2) {
                mp[s[i] - 'a']--;
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};