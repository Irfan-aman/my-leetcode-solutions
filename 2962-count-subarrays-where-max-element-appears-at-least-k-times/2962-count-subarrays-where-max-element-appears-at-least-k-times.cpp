class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0 , j=0;
        long long ans=0;
        int maxi=INT_MIN;
        for(int &x:nums) maxi=max(maxi,x);
        int maxCnt=0;
        while(j<n){
            if(nums[j]==maxi) maxCnt++;
            while(maxCnt==k){
                ans+=n-j;
                if(nums[i]==maxi) maxCnt--;
                i++;
            }
            j++;
        }
        return ans;
    }
};