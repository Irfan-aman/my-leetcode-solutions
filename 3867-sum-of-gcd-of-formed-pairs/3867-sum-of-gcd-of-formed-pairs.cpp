class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefGcd(n);
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            prefGcd[i]=__gcd(nums[i],maxi);
        }
        sort(prefGcd.begin(),prefGcd.end());
        long long ans=0;
        for(int i=0;i<n/2;i++){
            ans+=__gcd(prefGcd[i],prefGcd[n-i-1]);
        }
        return ans;
    }
};