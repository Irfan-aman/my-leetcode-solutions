class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double ans = -DBL_MAX;
        int sum = 0;
        int i = 0, j = 0;
        while (j < n) {
            sum += nums[j];
            if (j - i + 1 < k)
                j++;
            else if (j - i + 1 == k) {
                ans = max(ans, (double)sum / k);
                sum -= nums[i];
                i++;
                j++;
            }
        }
        return ans;
    }
};