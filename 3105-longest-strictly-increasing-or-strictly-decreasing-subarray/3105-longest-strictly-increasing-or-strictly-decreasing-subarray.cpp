class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        int currInc = 1, currDec = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] < nums[i]) {
                currInc++;
                ans = max(ans, currInc);
                currDec = 1;
            } else if (nums[i - 1] > nums[i]) {
                currDec++;
                ans = max(ans, currDec);
                currInc = 1;
            } else {
                currDec = 1;
                currInc = 1;
            }
        }
        return ans;
    }
};