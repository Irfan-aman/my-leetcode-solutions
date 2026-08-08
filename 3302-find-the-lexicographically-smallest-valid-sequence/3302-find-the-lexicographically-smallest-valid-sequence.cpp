class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<int> ans;
        vector<int> suffixMatch(n1, 0);
        int rightMatched = 0;
        int i = n1 - 1, j = n2 - 1;
        while (i >= 0) {
            if (j >= 0 && word1[i] == word2[j]) {
                rightMatched++;
                j--;
            }
            suffixMatch[i] = rightMatched;
            i--;
        }
        i = 0, j = 0;
        bool changePower = true;
        while (i < n1 && j < n2) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } else {
                if (changePower && i + 1 < n1 &&
                    suffixMatch[i + 1] >= n2 - j - 1) {
                    ans.push_back(i);
                    changePower = false;
                    j++;
                }
            }
            i++;
        }
        if (j == n2)
            return ans;
        return {};
    }
};