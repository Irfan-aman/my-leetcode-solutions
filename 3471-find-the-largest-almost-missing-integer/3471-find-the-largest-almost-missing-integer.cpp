class Solution {
public:
    int largetUniqueInt(vector<int>& nums) {
        vector<int> freq(51, 0); // idx=nums and freq[i]=freq of nums
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        for (int i = 50; i >= 1; i--) {
            if (freq[i] == 1) {
                return i;
            }
        }
        if (freq[0] == 1)
            return 0;
        return -1;
    }
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;
        if (k == 1)
            return largetUniqueInt(nums);
        else if (k == n)
            return *max_element(nums.begin(), nums.end());
        int firstNum = nums[0],
            lastNum = nums[n - 1]; // extreme numbers is the only possible ans
                                   // for k>1&& k<n
        int cntFirstN = 0, cntLastN = 0;
        for (int& x : nums) {
            if (x == firstNum)
                cntFirstN++;
            if (x == lastNum)
                cntLastN++;
        }
        if (cntLastN == 1)
            ans = max(ans, lastNum);
        if (cntFirstN == 1)
            ans = max(ans, firstNum);
        return ans;
    }
};