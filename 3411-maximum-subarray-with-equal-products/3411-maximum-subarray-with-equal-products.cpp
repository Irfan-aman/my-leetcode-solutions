class Solution {
public:
    typedef long long ll;
    int maxLength(vector<int>& nums) {
        int res = 1, n = nums.size();
        for (int i = 0; i < n; i++) {
            ll prod = 1;
            ll gcdVal = nums[i], lcmVal = nums[i];
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                gcdVal = gcd(gcdVal, nums[j]);
                lcmVal = lcm(lcmVal, nums[j]);
                if (prod == gcdVal * lcmVal) {
                    res = max(res, j - i + 1);
                } else if (prod > gcdVal * lcmVal)
                    break;
            }
        }
        return res;
    }
};