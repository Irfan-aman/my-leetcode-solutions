class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        unordered_set<string> st;
        string dna = "";
        int i = 0, j = 0;
        unordered_map<string, int> mp;
        while (j < n) {
            dna.push_back(s[j]);
            if (j - i + 1 < 10)
                j++;
            else {
                mp[dna]++;
                if (mp[dna] > 1) {
                    st.insert(dna);
                }
                dna = dna.substr(1);
                i++;
                j++;
            }
        }
        vector<string> res(st.begin(), st.end());
        return res;
    }
};