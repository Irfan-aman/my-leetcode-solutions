class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if (n == 1)
            return s;
        vector<int> mp(26, 0);
        string ans = "";
        for (int i = 0; i < n / 2; i++) {
            mp[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            ans.append(mp[i], i + 'a');
        }
        string rev = ans;
        reverse(rev.begin(), rev.end());
        if (n % 2 == 1)
            ans += s[n / 2];
        ans += rev;
        return ans;
    }
};