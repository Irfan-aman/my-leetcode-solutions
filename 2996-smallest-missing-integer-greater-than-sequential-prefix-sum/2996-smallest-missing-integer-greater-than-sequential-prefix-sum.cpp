class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int& x : nums)
            mp[x]++;
        int ans = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1] + 1) {
                while (mp.count(ans)) {
                    ans++;
                }
                break;
            }
            ans += nums[i];
        }
        return (n == 1) ? ans + 1 : ans;
    }
};