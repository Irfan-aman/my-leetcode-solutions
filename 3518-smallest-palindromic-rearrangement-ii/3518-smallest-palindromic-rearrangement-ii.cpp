class Solution {
public:
    typedef long long ll;
    ll nCr(int n, int r, int k) {
        ll ans = 1;
        for (int i = 1; i <= r; i++) {
            if (ans > k)
                return k + 1;
            ans = ans * (n - r + i) / i;
        }
        return ans;
    }
    ll countArrangements(vector<int>& freq, int letters, int k) {
        ll total = 1;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                int x = nCr(letters, freq[i], k);
                if (total > k / x)
                    return k + 1;
                total = total * x;
                letters -= freq[i];
            }
        }
        return total;
    }
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        char mid = '#';
        if (n % 2 == 1)
            mid = s[n / 2];
        int half = n / 2;
        vector<int> freq(26, 0);
        for (int i = 0; i < half; i++) {
            freq[s[i] - 'a']++;
        }
        ll total = countArrangements(freq, half, k);
        if (k > total)
            return "";

        string halfAns = "";

        for (int i = 0; i < half; i++) {
            for (int j = 0; j < 26; j++) {
                if (freq[j] > 0) {
                    freq[j]--;
                    long long ways = countArrangements(freq, half - i - 1, k);
                    if (k <= ways) {
                        halfAns.push_back(j + 'a');
                        break;
                    }
                    k -= ways;
                    freq[j]++;
                }
            }
        }
        string ans = halfAns;
        if (mid != '#')
            halfAns.push_back(mid);
        reverse(ans.begin(), ans.end());
        ans = halfAns + ans;
        return ans;
    }
};