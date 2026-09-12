class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> count(26);
        for (char& ch : sentence)
            count[ch - 'a']++;
        for (int& x : count) {
            if (x == 0)
                return false;
        }
        return true;
    }
};