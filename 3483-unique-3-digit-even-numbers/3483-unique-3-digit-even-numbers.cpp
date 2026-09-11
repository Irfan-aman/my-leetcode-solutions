class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> map(10);
        for (int& x : digits)
            map[x]++;
        int ans = 0;
        for (int i = 1; i <= 9; i++) {
            if (map[i] == 0)
                continue;
            map[i]--;
            for (int j = 0; j <= 9; j++) {
                if (map[j] == 0)
                    continue;
                map[j]--;
                for (int k = 0; k <= 8; k += 2) {
                    if (map[k] == 0)
                        continue;
                    ans++;
                }
                map[j]++;
            }
            map[i]++;
        }
        return ans;
    }
};