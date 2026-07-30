class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        if (n <= 8)
            return n;
        int ans = 0, cnt = 1;
        while (n) {
            if (n > 8) {
                ans += cnt * 8;
                n -= 8;
            } else {
                ans += cnt * n;
                n = 0;
            }
            cnt++;
        }
        return ans;
    }
};