class Solution {
public:
    void populateLPS(vector<int>& pat, vector<int>& lps) {
        int m = pat.size();
        int len = 0;
        int i = 1;
        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    bool KMPsearch(vector<int>& pattern, vector<int>& text) {
        int n = text.size();
        int m = pattern.size();
        vector<int> lps(m, 0);
        populateLPS(pattern, lps);
        int i = 0, j = 0;
        while (i < n) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            }
            if (j == m) {
                return true;
            } else if (i < n && text[i] != pattern[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }
    bool isRotationPossible(vector<int>& vec1, vector<int>& vec2) {
        vector<int> text = vec2;
        text.insert(text.end(), vec2.begin(), vec2.end());
        return KMPsearch(vec1, text);
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int res = 0;
        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;
            bool valid = true;
            for (int start = 0; start < n; start += k) {
                vector<int> vec1(nums.begin() + start,
                                 nums.begin() + start + k);
                vector<int> vec2(sorted.begin() + start,
                                 sorted.begin() + start + k);
                if (!isRotationPossible(vec1, vec2)) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                res += k;
        }
        return res;
    }
};