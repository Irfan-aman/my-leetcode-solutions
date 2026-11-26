class Solution {
public:
    bool canAliceWin(int n) {
        int step = (21 - sqrt(441 - 8 * n)) / 2;
        return step % 2 == 1;
    }
};