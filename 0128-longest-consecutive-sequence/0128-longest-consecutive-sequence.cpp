class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int res = 1;
        sort(nums.begin(), nums.end());
        int x = nums[0], currLen = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == x)
                continue;
            else if (nums[i] == x + 1) {
                currLen++;
                x++;
                res = max(res, currLen);
            } else {
                currLen = 1;
                x = nums[i];
            }
        }
        return res;
    }
};