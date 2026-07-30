class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        if (n <= 8)
            return n;
        else if (n <= 16)
            return 2 * n - 8; // 8+(n-8)*2
        else if (n <= 24)
            return 3 * n - 24; // 8+16+(n-16)*3
        return 4 * n - 48;     // 8+16+24 +(n-24)*4
    }
};
// if (n <= 8)
//             return n;
//         int ans = 0, cnt = 1;
//         while (n) {
//             if (n > 8) {
//                 ans += cnt * 8;
//                 n -= 8;
//             } else {
//                 ans += cnt * n;
//                 n = 0;
//             }
//             cnt++;
//         }