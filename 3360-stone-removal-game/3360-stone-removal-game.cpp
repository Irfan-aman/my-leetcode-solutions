class Solution {
public:
    bool canAliceWin(int n) {
        int x = 10;
        int step = 0;
        while (n >= x) {
            n -= x--;
            step++;
        }
        return step % 2 == 1;
    }
};