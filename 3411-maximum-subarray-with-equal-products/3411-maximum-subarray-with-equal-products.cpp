class Solution {
public:
    typedef long long ll;
    int maxLength(vector<int>& nums) {
        int res = 2, n = nums.size();
        ll prod = 1;
        int i = 0;
        for (int j = 0; j < n; j++) {
            while (gcd(prod, nums[j]) != 1) {
                prod /= nums[i];
                i++;
            }
            prod *= nums[j];
            res = max(res, j - i + 1);
        }
        return res;
    }
};