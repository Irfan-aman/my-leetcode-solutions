class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int total = 0;
        for (char& ch : s) {
            if (ch == '(')
                open++;
            else {
                open--;
            }
            if (open < 0) {
                total++;
                open = 0;
            }
        }
        return total + open;
    }
};