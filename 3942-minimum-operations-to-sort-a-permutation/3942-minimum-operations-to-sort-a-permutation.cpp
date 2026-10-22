class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        nums.insert(nums.end(), nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < 2 * n; i++) {
            if (nums[i] == 0 &&
                (i + 1 < 2 * n && nums[i + 1] == 1)) { // increasing
                res = min(i, n - i + 2);
                i++;
                while (i < 2 * n && nums[i] == nums[i - 1] + 1) {
                    i++;
                }
                if (nums[i - 1] == n - 1) {
                    return res;
                } else
                    break;
            } else if (nums[i] == n - 1 && i + 1 < 2 * n &&
                       nums[i + 1] == n - 2) { // decreasing
                res = min(i + 1, n - i + 1);
                i++;
                while (i < 2 * n && nums[i] == nums[i + 1] + 1) {
                    i++;
                }
                cout << res << " ";
                if (nums[i] == 0) {
                    return res;
                } else
                    break;
            }
        }
        return -1;
    }
};