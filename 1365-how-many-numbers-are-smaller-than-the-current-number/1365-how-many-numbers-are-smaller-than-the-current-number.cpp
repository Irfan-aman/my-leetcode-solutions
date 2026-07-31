class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<int> freq(101, 0);
        for (int& x : nums)
            freq[x]++;
        for (int i = 1; i <= 100; i++)
            freq[i] += freq[i - 1];
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0)
                ans[i] = freq[nums[i] - 1];
        }
        return ans;
    }
};