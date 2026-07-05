class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        int maxDiff=0;
        for(int &x:nums){
            int minDig=INT_MAX , maxDig=0;
            int m=x;
            while(m){
                int dig=m%10;
                minDig=min(minDig,dig);
                maxDig=max(maxDig,dig);
                m/=10;
            }
            int diff=maxDig-minDig;
            mp[diff].push_back(x);
            maxDiff=max(maxDiff,diff);
        }
        int ans=0;
        for(int &x:mp[maxDiff]){
            ans+=x;
        }
        return ans;
    }
};