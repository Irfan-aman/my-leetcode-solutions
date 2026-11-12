class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        int currInc = 1, currDec = 1;
        for (int i = 1; i < nums.size(); i++) {
            currInc = nums[i - 1] < nums[i] ? currInc + 1 : 1;
            currDec = nums[i - 1] > nums[i] ? currDec + 1 : 1;
            ans = max({ans, currDec, currInc});
        }
        return ans;
    }
};