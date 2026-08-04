class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX, maxi = INT_MIN;
        vector<bool> seen(101, false);
        for (int& x : nums) {
            mini = min(mini, x);
            maxi = max(maxi, x);
            seen[x] = true;
        }
        vector<int> ans;
        for (int i = mini + 1; i < maxi; i++) {
            if (!seen[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};