class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size(), n = nums2.size();
        int i = 0, j = m;
        int half = (m + n + 1) / 2;
        while (i <= j) {
            int px = i + (j - i) / 2;
            int py = half - px;
            // left half
            int x1 = (px == 0) ? INT_MIN : nums1[px - 1];
            int x2 = (py == 0) ? INT_MIN : nums2[py - 1];
            // right half
            int x3 = (px == m) ? INT_MAX : nums1[px];
            int x4 = (py == n) ? INT_MAX : nums2[py];
            if (x1 <= x4 && x2 <= x3) {
                if ((m + n) % 2 == 0) {
                    return (max(x1, x2) + min(x3, x4)) / 2.0;
                } else
                    return max(x1, x2);
            }
            if (x1 > x4) {
                j = px - 1;
            } else if (x2 > x3) {
                i = px + 1;
            }
        }
        return -1;
    }
};