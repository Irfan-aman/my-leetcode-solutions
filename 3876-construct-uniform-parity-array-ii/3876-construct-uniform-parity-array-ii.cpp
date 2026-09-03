class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int minOdd = INT_MAX, minEven = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (nums1[i] & 1) {
                minOdd = min(minOdd, nums1[i]);
            } else {
                minEven = min(minEven, nums1[i]);
            }
        }
        if (minEven == INT_MAX || minOdd == INT_MAX) {
            return true;
        }
        return minEven > minOdd; //to make even no odd and minEven - minOdd >=1 ;
    }
};