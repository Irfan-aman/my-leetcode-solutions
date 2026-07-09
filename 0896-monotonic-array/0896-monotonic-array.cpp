class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return true;
        int i=1;
        while(nums[i-1]<=nums[i]){//check increasing
            i++;
            if(i==n)return true;
        }
        i=1;
        while(nums[i-1]>=nums[i]){//check decreasing
            i++;
            if(i==n)return true;
        }

        return false;
    }
};