class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxInc = 1, maxDec = 1;
        int currInc = 1, currDec = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] < nums[i]) {
                currInc++;
                currDec = 1;
            } else if (nums[i - 1] > nums[i]) {
                currDec++;
                currInc = 1;
            } else {
                currDec = 1;
                currInc = 1;
            }
            maxInc = max(maxInc, currInc);
            maxDec = max(maxDec, currDec);
        }
        return max(maxDec, maxInc);
    }
};