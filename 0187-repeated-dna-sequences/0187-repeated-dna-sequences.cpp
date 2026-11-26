class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string> res;
        string dna = s.substr(0, 9);
        unordered_map<string, int> mp;
        for (int i = 9; i < n; i++) {
            dna.push_back(s[i]);
            mp[dna]++;
            if (mp[dna] == 2) {
                res.push_back(dna);
            }
            dna = dna.substr(1);
        }

        return res;
    }
};