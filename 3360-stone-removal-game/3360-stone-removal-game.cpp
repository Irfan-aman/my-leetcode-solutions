class Solution {
public:
    bool canAliceWin(int n) {
        int x = 10;
        bool res = false;
        while (n) {
            if (n < x)
                return res;
            else
                n -= x;
            x--;
            res = !res;
        }
        return res;
    }
};