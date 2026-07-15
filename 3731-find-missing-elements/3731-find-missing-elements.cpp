class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mini=nums[0];
        int maxi=nums[n-1];
        vector<bool> seen(101,false);
        for(int &x:nums){
            seen[x]=true;
        }
        vector<int> ans;
        for(int i=mini;i<=maxi;i++){
            if(!seen[i]) ans.push_back(i);
        }
        return ans;
    }
};