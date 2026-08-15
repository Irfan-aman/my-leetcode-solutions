class Solution {
public:
    int fib(int n) {
        if (n <= 1)
            return n;
        int a = 0, b = 1;
        for (int i = 2; i <= n; i++) {
            int fib_i = a + b;
            a = b;
            b = fib_i;
        }
        return b;
    }
};