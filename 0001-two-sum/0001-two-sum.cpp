class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int tar=target-nums[i];
            if(mp.count(tar)){
                return {mp[tar],i};
            }
            mp[nums[i]]=i;
        }
        return {-1,-1};
    }
};