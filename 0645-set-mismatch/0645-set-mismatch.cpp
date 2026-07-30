class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int currSum = 0, trueSum = n * (n + 1) / 2;
        int dup = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (mp.count(nums[i]))
                dup = nums[i];
            mp[nums[i]]++;
            currSum += nums[i];
        }
        int missNo = trueSum - currSum + dup;
        return {dup, missNo};
    }
};