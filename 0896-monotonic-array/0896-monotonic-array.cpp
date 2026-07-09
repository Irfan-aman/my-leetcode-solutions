class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        bool inc=false , dec=false;
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]) inc=true;
            if(nums[i-1]>nums[i]) dec=true;
        }
        if(inc && dec) return false;

        return true;
    }
};