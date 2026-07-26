class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int m1 = INT_MIN, m2 = INT_MIN, m3 = INT_MIN, s1 = INT_MAX,
            s2 = INT_MAX;
        for (int& x : nums) {
            if (x >= m1) {
                m3 = m2;
                m2 = m1;
                m1 = x;
            } else if (x >= m2) {
                m3 = m2;
                m2 = x;
            } else if (x >= m3) {
                m3 = x;
            }
            if (x <= s1) {
                s2 = s1;
                s1 = x;
            } else if (x <= s2) {
                s2 = x;
            }
        }

        return max(m1 * m2 * m3, m1 * s1 * s2);
    }
};

// int n = nums.size();
//         sort(begin(nums), end(nums), greater<int>());
//         return max(nums[0] * nums[1] * nums[2],
//                    nums[0] * nums[n - 1] * nums[n - 2]);