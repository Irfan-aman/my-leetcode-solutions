class Solution {
public:
    string result = "";
    char midChar = '#';
    int halfLen = 0;
    bool solve(string& curr, vector<int>& freq, string& target, int i,
               bool greater) {
        if (curr.size() == halfLen) {
            string left = curr;
            string right = left;
            reverse(right.begin(), right.end());
            if (midChar != '#') {
                left += midChar;
            }
            string candidate = left + right;
            if (candidate > target) {
                result = candidate;
                return true;
            }
            return false;
        }
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (freq[ch - 'a'] == 0)
                continue;
            if (!greater && ch < target[i])
                continue;
            bool isGreater = greater || (ch > target[i]);
            curr.push_back(ch);
            freq[ch - 'a']--;
            if (solve(curr, freq, target, i + 1, isGreater)) {
                return true;
            }
            curr.pop_back();
            freq[ch - 'a']++;
        }
        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char& ch : s)
            freq[ch - 'a']++;
        bool mid = false;
        for (int i = 0; i < 26; i++) {
            if (!mid && (freq[i] & 1) == 1) {
                mid = true;
                midChar = i + 'a';
            } else if (mid && (freq[i] & 1) == 1) {
                return "";
            }
            freq[i] /= 2;
        }
        halfLen = n / 2;
        string curr;
        solve(curr, freq, target, 0, false);

        return result;
    }
};