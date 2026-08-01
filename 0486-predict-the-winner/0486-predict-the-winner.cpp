class Solution {
public:
    int solve(int i, int j, vector<int>& nums) {
        if (i > j)
            return 0;
        if (i == j)
            return nums[i];
        int take_i =
            nums[i] +
            min((i < nums.size() && j >= 0) ? solve(i + 2, j, nums) : 0,
                (i < nums.size() && j >= 0) ? solve(i + 1, j - 1, nums) : 0);
        int take_j =
            nums[j] +
            min((i < nums.size() && j >= 0) ? solve(i + 1, j - 1, nums) : 0,
                (i < nums.size() && j >= 0) ? solve(i, j - 2, nums) : 0);
        return max(take_i, take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for (int& x : nums)
            total += x;
        int p1 = solve(0, n - 1, nums);
        int p2 = total - p1;
        return p1 >= p2;
    }
};