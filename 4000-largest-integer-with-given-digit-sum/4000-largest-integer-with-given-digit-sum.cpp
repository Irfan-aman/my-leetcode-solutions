class Solution {
public:
    int largestInteger(int n, int s) {
        int ans = 0;
        while (n) {
            if (s > 9) {
                ans = ans * 10 + 9;
                s -= 9;
                n--;
            } else {
                ans = ans * 10 + s;
                s = 0;
                n--;
            }
        }
        return s == 0 ? ans : -1;
    }
};