class Solution {
public:
    int minRotations(string s) {
        int curr = 0;
        int total = 0;
        for (char& ch : s) {
            int dig = ch - '0';
            total += min(abs(curr - dig), 10 - abs(curr - dig));
            curr = dig;
        }
        return total;
    }
};