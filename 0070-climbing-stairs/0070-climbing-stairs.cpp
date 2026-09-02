class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;
        int a = 1, b = 2; // for n=1 => a , n=2=>b =>base case
        for (int i = 3; i <= n; i++) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};