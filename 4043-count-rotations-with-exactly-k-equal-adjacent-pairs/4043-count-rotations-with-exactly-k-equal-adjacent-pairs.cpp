class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int score = 0;
            for (int j = i; j < i + n - 1; j++) {
                if (s[j % n] == s[(j + 1) % n])
                    score++;
            }
            if (score == k)
                res++;
        }
        return res;
    }
};