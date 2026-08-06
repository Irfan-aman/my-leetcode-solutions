class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end());
        vector<int> num1(s1.begin(), s1.end());
        set<int> s2(nums2.begin(), nums2.end());
        vector<int> num2(s2.begin(), s2.end());
        vector<int> ans;
        int i = 0, j = 0;
        while (i < num1.size() && j < num2.size()) {
            if (num1[i] == num2[j]) {
                ans.push_back(num1[i]);
                i++;
                j++;
            } else if (num1[i] < num2[j])
                i++;
            else
                j++;
        }
        return ans;
    }
};