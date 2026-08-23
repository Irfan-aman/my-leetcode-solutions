class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                res += nums[i - 1] * nums[i - 1];
                int j = n / i;
                if (j != i) {
                    res += nums[j - 1] * nums[j - 1];
                }
            }
        }
        return res;
    }
};