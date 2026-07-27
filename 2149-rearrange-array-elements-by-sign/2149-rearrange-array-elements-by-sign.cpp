class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos, neg;
        for (int k = 0; k < n; k++) {
            if (nums[k] > 0) {
                pos.push_back(k);
            } else if (nums[k] < 0) {
                neg.push_back(k);
            }
        }
        int i = 0, j = 0;
        vector<int> ans;
        while (i < pos.size() || j < neg.size()) {
            if (i < pos.size())
                ans.push_back(nums[pos[i++]]);
            if (j < neg.size())
                ans.push_back(nums[neg[j++]]);
        }
        return ans;
    }
};