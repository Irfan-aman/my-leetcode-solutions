class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int k = n - 1; k >= 2; k--) {
            int l = 0, r = k - 1;
            while (l <= r) {
                if (nums[l] + nums[r] > nums[k]) { // valid triangle
                    res += r - l; // stores all number between r and l
                    r--;
                } else { // Invalid so increment l
                    l++;
                }
            }
        }
        return res;
    }
};