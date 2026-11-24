class Solution {
public:
    typedef long long ll;
    int maxLength(vector<int>& nums) {
        int res = 2, n = nums.size();
        ll prod = 1;
        int i = 0;
        for (int j = 0; j < n; j++) {
            if (gcd(prod, nums[j]) == 1) {
                res = max(res, j - i + 1);
            }
            while (gcd(prod, nums[j]) != 1) {
                prod /= nums[i];
                i++;
            }
            prod *= nums[j];
        }
        return res;
    }
};