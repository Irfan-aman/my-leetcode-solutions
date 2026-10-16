class Solution {
public:
    int MOD = 1e9 + 7;
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> st;
            for (int j = i; j < n; j++) {
                st.insert(nums[j]);
                res += st.size() * st.size();
            }
        }
        return res % MOD;
    }
};