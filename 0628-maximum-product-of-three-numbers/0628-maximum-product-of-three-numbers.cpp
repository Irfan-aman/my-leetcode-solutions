class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums), greater<int>());
        int negCnt = 0;
        for (int& x : nums)
            if (x < 0)
                negCnt++;
        int ans = nums[0] * nums[1] * nums[2];
        if (negCnt >= 2) {
            ans = max(ans, nums[0] * nums[n - 1] * nums[n - 2]);
        }
        return ans;
    }
};