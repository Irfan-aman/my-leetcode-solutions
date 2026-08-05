class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int l = 1; // length of x;
        int ans = 0;
        int n1 = str1.size(), n2 = str2.size();
        while (l <= min(n1, n2)) {
            string temp = str1.substr(0, l);
            if (n1 % l == 0 && n2 % l == 0) {
                string t = "";
                for (int i = 0; i < n1 / l; i++)
                    t += temp;
                if (str1 == t) {
                    t.clear();
                    for (int i = 0; i < n2 / l; i++)
                        t += temp;
                    if (str2 == t) {
                        ans = l;
                    }
                }
            }
            l++;
        }
        return str1.substr(0, ans);
    }
};