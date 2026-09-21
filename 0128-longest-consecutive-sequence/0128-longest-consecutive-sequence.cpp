class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int res = 1;
        unordered_set<int> st;
        for (int& x : nums)
            st.insert(x);
        for (auto x : st) {
            if (!st.count(x - 1)) {
                int currLen = 1;
                while (st.count(x + 1)) {
                    currLen++;
                    x++;
                    res = max(res, currLen);
                }
            }
        }
        return res;
    }
};