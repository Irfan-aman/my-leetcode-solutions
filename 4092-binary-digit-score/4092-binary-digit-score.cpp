class Solution {
public:
    int findSetBits(int x) {
        int totalBitSet = 0;
        while (x) {
            if (x & 1) {
                totalBitSet++;
            }
            x >>= 1;
        }
        return totalBitSet;
    }
    int calculateScore(int a, int b) {
        int s1 = findSetBits(a);
        int s2 = findSetBits(b);
        return s1 >= s2 ? s1 * s2 : s2 / s1;
    }
};