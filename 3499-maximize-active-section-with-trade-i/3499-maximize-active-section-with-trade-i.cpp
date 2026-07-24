class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int left = -1; // for a particular active section, the total number of
                       // inactive sec to its left
        int ans = 0;
        int active = count(s.begin(), s.end(), '1');
        if(active==0 || n<=2)return active;
        for (int i = 0; i < n; ) {
            if (s[i] == '1'){
                i++;continue;
            }
            int start = i;
            while (i < n && s[i] == '0')
                i++;
            int right = i - start;
            if (left != -1) {
                ans = max(ans, left + right);
            }
            left = right;
        }
        return ans + active;
    }
};