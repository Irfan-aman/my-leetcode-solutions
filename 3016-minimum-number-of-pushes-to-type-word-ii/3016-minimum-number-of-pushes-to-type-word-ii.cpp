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
        for (int i = 0; i < 26; i += 8) {
            int totalWord = 0;
            for (int j = i; j < i + 8 && j < 26; j++) {
                totalWord += freq[j];
            }
            ans += totalWord * pushCnt;
            pushCnt++;
        }
        return ans;
    }
};