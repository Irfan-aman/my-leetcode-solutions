class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        int maxi = INT_MIN;
        for (int& x : nums)
            maxi = max(maxi, x);
        vector<int> maxIdx;
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxi)
                maxIdx.push_back(i);
            int sizes = maxIdx.size();
            if (sizes >= k) {
                int last_i = maxIdx[sizes - k];
                ans += last_i + 1;
            }
        }
        return ans;
    }
};