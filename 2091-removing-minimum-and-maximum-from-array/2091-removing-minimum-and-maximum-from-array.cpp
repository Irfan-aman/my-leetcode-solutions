class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return n;
        int mini = 0, maxi = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[mini])
                mini = i;
            if (nums[i] > nums[maxi])
                maxi = i;
        }
        int leftIdx = min(mini, maxi);
        int rightIdx = max(mini, maxi);
        int res =
            min((leftIdx + 1) + (n - rightIdx), min(rightIdx + 1, n - leftIdx));
        return res;
    }
};