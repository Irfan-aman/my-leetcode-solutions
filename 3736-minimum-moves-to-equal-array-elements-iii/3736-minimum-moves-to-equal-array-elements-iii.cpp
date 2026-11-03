class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int sum = 0;
        for (int& x : nums) {
            sum += x;
            maxi = max(maxi, x);
        }
        return n * maxi - sum;
    }
};