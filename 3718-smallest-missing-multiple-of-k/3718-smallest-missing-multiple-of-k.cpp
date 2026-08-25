class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st;
        for (int& x : nums)
            st.insert(x);
        int i = k;
        while (true) {
            if (!st.count(i)) {
                return i;
            }
            i += k;
        }
    }
};