class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> freq(26, 0);
        for (char& ch : word)
            freq[ch - 'a']++;
        sort(freq.begin(), freq.end(), greater<int>());
        if (n <= 8)
            return n;
        int ans = 0, pushCnt = 1;
        for (int i = 0; i < 26; i++) {
            int totalWord = 0;
            for (; i < 8; i++) {
                totalWord += freq[i];
            }
            ans += totalWord * pushCnt;
            totalWord = 0;
            pushCnt++;
            for (; i < 16; i++) {
                totalWord += freq[i];
            }
            ans += totalWord * pushCnt;
            totalWord = 0;
            pushCnt++;
            for (; i < 24; i++) {
                totalWord += freq[i];
            }
            ans += totalWord * pushCnt;
            totalWord = 0;
            pushCnt++;
            for (; i < 26; i++) {
                totalWord += freq[i];
            }
            ans += totalWord * pushCnt;
            totalWord = 0;
            pushCnt++;
        }
        return ans;
    }
};