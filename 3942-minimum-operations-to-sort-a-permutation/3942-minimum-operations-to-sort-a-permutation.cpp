class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int acs_count = 0, dsc_count = 0;
        for (int i = 1; i < n; i++) {
            acs_count += (nums[i] == (nums[i - 1] + 1) % n);
            dsc_count += (nums[i - 1] == (nums[i] + 1) % n);
        }
        if (acs_count == n - 1 && nums[0] == 0)
            return 0;
        if (acs_count == n - 1) {
            return min(n - nums[0], 1 + (nums[n - 1] + 1) +
                                        1); // min of left and right rotation
        }
        if (dsc_count == n - 1) {
            return min(n - nums[n - 1] + 1,
                       (nums[0] + 1) % n + 1); // min of left and right rotation
        }
        return -1;
    }
};