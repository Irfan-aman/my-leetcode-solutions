class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        int i = 0, j = 0;
        int res = 0;
        while (j < n) {
            mp[s[j]]++;
            while (mp.size() == 3) {
                res += n - j;
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
            j++;
        }
        return res;
    }
};