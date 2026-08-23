class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int leftSum = 0, rightSum = 0;
        int leftQnCount = 0, rightQnCount = 0;
        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                if (num[i] == '?') {
                    leftQnCount++;
                } else {
                    leftSum += num[i] - '0';
                }
            } else {
                if (num[i] == '?') {
                    rightQnCount++;
                } else {
                    rightSum += num[i] - '0';
                }
            }
        }
        if ((leftQnCount + rightQnCount) & 1) { // odd '?' count
            return true;
        }
        return (2 * leftSum + 9 * leftQnCount) !=
               (2 * rightSum + 9 * rightQnCount);
    }
};