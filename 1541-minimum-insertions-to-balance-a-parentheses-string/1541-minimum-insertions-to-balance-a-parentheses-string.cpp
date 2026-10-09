class Solution {
public:
    int minInsertions(string s) {
        int count = 0;
        int res = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                count++;
            } else {
                if (count == 0 && (i + 1 < n && s[i + 1] == ')')) {
                    res++;
                    i++;
                } else if (count == 0 &&
                           ((i + 1 < n && s[i + 1] == '(') || i + 1 >= n)) {
                    res += 2;
                } else if (count != 0) {
                    if (i + 1 < n && s[i + 1] == ')') {
                        count--;
                        i++;
                    } else if ((i + 1 < n && s[i + 1] == '(') || i + 1 == n) {
                        res++;
                        count--;
                    }
                }
            }
        }
        res += count * 2;
        return res;
    }
};