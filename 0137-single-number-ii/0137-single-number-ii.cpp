class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int cnt = 0;
            for (int& x : nums) {
                if (x & 1)
                    cnt++;
                x >>= 1;
            }
            if (cnt % 3 == 1) {
                ans |= (1 << i);
            }
        }

        return ans;
    }
};