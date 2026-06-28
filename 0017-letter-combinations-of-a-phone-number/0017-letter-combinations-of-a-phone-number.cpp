class Solution {
public:
    void solve(string& digits, int idx, unordered_map<char, string>& mp,
               vector<string>& ans, string& str) {
        if (idx == digits.size()) {
            ans.push_back(str);
            return;
        }

        char ch = digits[idx];
        string lett = mp[ch];
        for (char& c : lett) {
            str.push_back(c);
            solve(digits, idx + 1, mp, ans, str);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> ans;
        string str = "";
        solve(digits, 0, mp, ans, str);
        return ans;
    }
};