class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> targetIdx;
        int lessCount = 0; // total number of elements less than target
        int targetCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < target)
                lessCount++;
            else if (nums[i] == target)
                targetCount++;
        }
        int start = lessCount;
        while (targetCount--) {
            targetIdx.push_back(start);
            start++;
        }
        return targetIdx;
    }
};