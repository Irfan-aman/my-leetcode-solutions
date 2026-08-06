class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums1.begin(), nums1.end());
        vector<int> ans;
        for (int& x : nums2) {
            if (st.erase(x)) { // return 1 if x exist in st
                ans.push_back(x);
            }
        }
        return ans;
    }
};