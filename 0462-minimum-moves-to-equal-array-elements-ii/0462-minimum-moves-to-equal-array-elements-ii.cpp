class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int mid = nums[n / 2];
        int res = 0;
        for (int& x : nums) {
            res += abs(mid - x);
        }
        return res;
    }
};