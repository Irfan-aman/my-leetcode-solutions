class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negativeCount = 0;
        for (int& x : nums) {
            if (x == 0) {
                return 0;
            } else if (x < 0) {
                negativeCount++;
            }
        }
        return (negativeCount & 1) ? -1 : 1;
    }
};