class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a = 0, b = sqrt(c);
        while (a <= b) {
            long long sum = a * a + b * b;
            if (sum < c) {
                a++;
            } else if (sum > c) {
                b--;
            } else {
                return true;
            }
        }
        return false;
    }
};