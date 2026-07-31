class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> set;
        for (int& x : nums)
            set.insert(x);
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (set.count(i) == 0)
                ans.push_back(i);
        }
        return ans;
    }
};