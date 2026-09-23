class Solution {
public:
    typedef long long ll;
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        ll totalSum = 0;
        for (int& i : nums)
            totalSum += i;
        int tar = totalSum - x;
        int i = 0, j = 0;
        ll sum = 0;
        int maxSubarr = -1;
        while (j < n) {
            sum += nums[j];
            while (i <= j && sum > tar) {
                sum -= nums[i];
                i++;
            }
            if (sum == tar) {
                maxSubarr = max(maxSubarr, j - i + 1);
            }
            j++;
        }
        if (maxSubarr == -1) {
            return -1;
        }
        return n - maxSubarr;
    }
};