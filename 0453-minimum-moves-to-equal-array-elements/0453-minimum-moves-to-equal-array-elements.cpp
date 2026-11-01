class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int minEl = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] < minEl)
                minEl = nums[i];
        }
        for (int i = 0; i < n; i++) {
            res += (nums[i] - minEl);
        }
        return res;
    }
};