class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if (is_sorted(s.begin(), s.end()))
            return 0;
        if (n == 2)
            return -1;
        char min_char = s[0], max_char = s[n - 1];
        char min_mid = s[1], max_mid = s[n - 2];
        for (int i = 0; i < n; i++) {
            if (s[i] < min_char)
                min_char = s[i];
            if (s[i] > max_char)
                max_char = s[i];
            if (i >= 1 && i < n - 1) {
                if (s[i] < min_mid)
                    min_mid = s[i];
                if (s[i] > max_mid)
                    max_mid = s[i];
            }
        }
        if (min_char == s[0] || max_char == s[n - 1])
            return 1;
        else if (s[0] > max_mid && min_mid > s[n - 1])
            return 3;
        return 2;
    }
};