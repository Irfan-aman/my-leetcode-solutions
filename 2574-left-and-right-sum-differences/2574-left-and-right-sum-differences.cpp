class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        int rSum=0;
        for(int &x:nums) rSum+=x;
        int lSum=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            rSum-=nums[i];
            ans.push_back(abs(rSum-lSum));
            lSum+=nums[i];
        }
        return ans;
    }
};