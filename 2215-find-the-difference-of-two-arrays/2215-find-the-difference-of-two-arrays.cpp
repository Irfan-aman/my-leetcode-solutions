class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums2.begin(), nums2.end());
        unordered_set<int> st;
        for (int& x : nums1) {
            if (st1.count(x) == 0)
                st.insert(x);
        }
        vector<int> ans0(st.begin(), st.end());
        unordered_set<int> st2(nums1.begin(), nums1.end());
        st.clear();
        for (int& x : nums2) {
            if (st2.count(x) == 0)
                st.insert(x);
        }
        vector<int> ans1(st.begin(), st.end());
        return {ans0, ans1};
    }
};