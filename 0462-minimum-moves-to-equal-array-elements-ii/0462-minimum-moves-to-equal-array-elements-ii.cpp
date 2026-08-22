class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mid = nums[n / 2];
        int minMoves = 0;
        for (int& x : nums) {
            minMoves += abs(mid - x);
        }
        return minMoves;
    }
};