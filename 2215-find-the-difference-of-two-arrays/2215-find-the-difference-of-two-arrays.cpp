class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums1.begin(), nums1.end());
        unordered_set<int> st2(nums2.begin(), nums2.end());
        vector<int> ans0;
        vector<int> ans1;
        for (auto& x : st1) {
            if (!st2.count(x))
                ans0.push_back(x);
        }
        for (auto& x : st2) {
            if (!st1.count(x))
                ans1.push_back(x);
        }
        return {ans0, ans1};
    }
};