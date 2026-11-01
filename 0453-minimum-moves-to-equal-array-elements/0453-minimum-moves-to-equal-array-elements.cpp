class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++) {
            res += (nums[i] - nums[0]);
        }
        return res;
    }
};