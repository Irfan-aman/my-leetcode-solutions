class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX, secMin = INT_MAX, thirdMin = INT_MAX,
            maxi = INT_MIN, secMax = INT_MIN, thirdMax = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= mini) {
                thirdMin = secMin;
                secMin = mini;
                mini = nums[i];
            } else if (nums[i] <= secMin) {
                thirdMin = secMin;
                secMin = nums[i];
            } else if (nums[i] < thirdMin)
                thirdMin = nums[i];
            if (nums[i] >= maxi) {
                thirdMax = secMax;
                secMax = maxi;
                maxi = nums[i];
            } else if (nums[i] >= secMax) {
                thirdMax = secMax;
                secMax = nums[i];
            } else if (nums[i] > thirdMax)
                thirdMax = nums[i];
        }
        return min({secMax - secMin, maxi - thirdMin, thirdMax - mini});
    }
};