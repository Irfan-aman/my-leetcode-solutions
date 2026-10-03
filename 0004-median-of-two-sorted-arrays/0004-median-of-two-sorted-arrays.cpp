class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int elem1 = -1, elem2 = -1;
        int k = 0;
        int mid = (m + n + 1) / 2;
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                if (k == mid - 1) {
                    elem1 = nums1[i];
                } else if (k == mid) {
                    elem2 = nums1[i];
                }
                i++;
            } else {
                if (k == mid - 1) {
                    elem1 = nums2[j];
                } else if (k == mid) {
                    elem2 = nums2[j];
                }
                j++;
            }
            k++;
        }
        while (i < m) {
            if (k == mid - 1) {
                elem1 = nums1[i];
            } else if (k == mid) {
                elem2 = nums1[i];
            }
            i++;
            k++;
        }
        while (j < n) {
            if (k == mid - 1) {
                elem1 = nums2[j];
            } else if (k == mid) {
                elem2 = nums2[j];
            }
            j++;
            k++;
        }
        if ((m + n) % 2 == 1) {
            return elem1;
        }
        return (elem1 + elem2) / 2.0;
    }
};