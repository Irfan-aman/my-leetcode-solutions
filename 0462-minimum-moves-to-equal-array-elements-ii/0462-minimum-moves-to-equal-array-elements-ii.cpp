class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mid = nums[n / 2];
        int res = 0;
        for (int& x : nums) {
            res += abs(mid - x);
        }
        return res;
    }
};