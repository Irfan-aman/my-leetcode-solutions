class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numIdx;
        for (int i = 0; i < nums.size(); i++) {
            if (numIdx.find(target - nums[i]) != numIdx.end()) {
                return {numIdx[target - nums[i]], i};
            }
            numIdx[nums[i]] = i;
        }
        return {};
    }
};