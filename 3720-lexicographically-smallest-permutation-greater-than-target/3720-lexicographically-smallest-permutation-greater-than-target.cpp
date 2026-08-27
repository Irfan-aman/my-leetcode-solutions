class Solution {
public:
    string res = "";
    bool solve(string& curr, vector<int>& freq, string& target, int i,
               bool greater) {
        if (i == target.size()) {
            if (greater) {
                res = curr;
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
            curr.push_back(ch);                                //  DO
            freq[ch - 'a']--;                                  //  Do
            if (solve(curr, freq, target, i + 1, isGreater)) { // EXPLORE
                return true;
            }
            curr.pop_back();  // UNDO
            freq[ch - 'a']++; // UNDO
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char& ch : s)
            freq[ch - 'a']++;
        string curr;
        solve(curr, freq, target, 0, false);
        return res;
    }
};