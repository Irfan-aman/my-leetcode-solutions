class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> targetIdx;
        int less = 0; // total number of elements less than target
        int totalTar = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < target)
                less++;
            else if (nums[i] == target)
                totalTar++;
        }
        int i = less;
        while (totalTar--) {
            targetIdx.push_back(i);
            i++;
        }
        return targetIdx;
    }
};