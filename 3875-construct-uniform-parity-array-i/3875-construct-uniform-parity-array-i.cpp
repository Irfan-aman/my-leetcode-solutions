class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        //If all even in nums1 or all odd => always true;
        //If some even and some odd => we can make all elem. in nums2 odd (by subracting even - odd =>odd)
        //so always true;
        return true;
    }
};