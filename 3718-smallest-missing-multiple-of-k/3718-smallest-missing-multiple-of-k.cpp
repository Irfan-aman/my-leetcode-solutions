class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        for (int i = k;; i += k) {
            if (!st.count(i)) {
                return i;
            }
        }
    }
};