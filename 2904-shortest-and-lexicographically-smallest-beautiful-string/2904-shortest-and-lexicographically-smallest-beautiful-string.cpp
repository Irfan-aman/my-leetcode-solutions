class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string res = "";
        int i = 0;
        int oneCount = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1')
                oneCount++;
            if (oneCount < k) {
                continue;
            }
            while (i < n && oneCount > k) {
                if (s[i] == '1')
                    oneCount--;
                i++;
            }
            if (oneCount == k) {
                while (s[i] == '0')
                    i++;
            }
            string curr = s.substr(i, j - i + 1);
            if (res.empty() || (res.size() > curr.size()) ||
                (res.size() == curr.size() && curr < res)) {
                res = curr;
            }
        }
        return res;
    }
};