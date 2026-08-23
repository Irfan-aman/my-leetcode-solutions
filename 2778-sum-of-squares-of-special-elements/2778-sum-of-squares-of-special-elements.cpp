class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int i = 1;
        while (n / i > 0) {
            if (n % i == 0) {
                res += (nums[i - 1] * nums[i - 1]);
            }
            i++;
        }
        return res;
    }
};