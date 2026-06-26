class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int leftValidPt=0;
        int cumSum=0;
        mp[0]=1;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                leftValidPt+=mp[cumSum];
                cumSum++;
            }else{
                cumSum--;
                leftValidPt-=mp[cumSum];
            }
            mp[cumSum]++;
            ans+=leftValidPt;
        }
        return ans;
    }
};