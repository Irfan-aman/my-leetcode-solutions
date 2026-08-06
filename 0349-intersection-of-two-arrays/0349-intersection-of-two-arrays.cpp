class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums1.begin(), nums1.end());
        unordered_set<int> s2;
        for (int& x : nums2) {
            if (st.count(x)) {
                s2.insert(x);
            }
        }
        vector<int> ans(s2.begin(), s2.end());
        return ans;
    }
};