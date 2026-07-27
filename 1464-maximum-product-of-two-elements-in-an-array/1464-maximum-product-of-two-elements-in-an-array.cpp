class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int firstMax = 0, secMax = 0;
        for (int& x : nums) {
            if (x >= firstMax) {
                secMax = firstMax;
                firstMax = x;
            } else if (x > secMax) {
                secMax = x;
            }
        }
        return (firstMax - 1) * (secMax - 1);
    }
};