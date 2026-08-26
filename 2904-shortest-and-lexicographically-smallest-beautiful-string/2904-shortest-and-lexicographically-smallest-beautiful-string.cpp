class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string res = "";
        int i = 0, j = 0;
        int oneCount = count(s.begin(), s.end(), '1');
        if (oneCount == 0) {
            return "";
        } else {
            if (k == 1) {
                return "1";
            }
            oneCount = 0;
        }
        while (j < n) {
            if (s[j] == '1')
                oneCount++;
            if (oneCount < k) {
                j++;
                continue;
            }
            if (res.size() > k) {
                while (i < n && oneCount > k) {
                    if (s[i] == '1')
                        oneCount--;
                    i++;
                }
                while (s[i] == '0')
                    i++;
            }
            if (res.empty()) {
                while (s[i] == '0') {
                    i++;
                }
                res = s.substr(i, j - i + 1);
            } else if (!res.empty() && res.size() > j - i + 1) {
                while (s[i] == '0') {
                    i++;
                }
                res = s.substr(i, j - i + 1);
            } else if (!res.empty() && res.size() == j - i + 1) {
                while (s[i] == '0') {
                    i++;
                }
                string str = s.substr(i, j - i + 1);
                if (str < res) {
                    res = str;
                }
            }
            j++;
        }
        return res;
    }
};