class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int minOdd = INT_MAX, minEven = INT_MAX, totalEven = 0, totalOdd = 0;
        for (int i = 0; i < n; i++) {
            if (nums1[i] & 1) {
                totalOdd++;
                minOdd = min(minOdd, nums1[i]);
            } else {
                totalEven++;
                minEven = min(minEven, nums1[i]);
            }
        }
        if (totalOdd == n || totalEven == n) {
            return true;
        }
        return (minEven - minOdd) >= 1;
    }
};