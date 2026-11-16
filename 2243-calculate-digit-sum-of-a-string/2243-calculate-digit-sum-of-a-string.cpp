class Solution {
public:
    string digitSum(string s, int k) {
        if(s.size()<=k)return s;
        string t = s;
        while (true) {
            string newT = "";
            int curr = 0;
            int p = 0;
            for (int i = 0; i < t.size(); i++) {
                curr += t[i] - '0';
                p++;
                if (p == k || i == t.size() - 1) {
                    newT += to_string(curr);
                    curr = 0;
                    p = 0;
                }
            }
            if (newT.size() <= k) {
                return newT;
            }
            t = newT;
        }
        return t;
    }
};