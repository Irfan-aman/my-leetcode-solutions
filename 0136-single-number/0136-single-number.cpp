class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorSum = 0;
        for (int& x : nums)
            xorSum ^= x;
        return xorSum;
    }
};