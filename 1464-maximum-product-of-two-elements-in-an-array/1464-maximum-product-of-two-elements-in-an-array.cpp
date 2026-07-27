class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int firstMax = INT_MIN, secMax = INT_MIN;
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