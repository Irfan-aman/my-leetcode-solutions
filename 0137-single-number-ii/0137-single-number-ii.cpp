class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        sort(nums.begin(), nums.end());
        int ans = nums[0];
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1]) {
                ans = nums[i];
                break;
            }
        }
        if (nums[n - 1] != nums[n - 2])
            ans = nums[n - 1];
        return ans;
    }
};