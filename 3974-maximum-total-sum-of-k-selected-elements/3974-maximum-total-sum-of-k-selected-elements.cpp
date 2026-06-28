class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end(),greater<int>());
        long long ans=0;
        for(int &x:nums){
            if(k==0) break;
            else if(mul>0){
                ans+=1ll*x*mul;
                mul--;
            }else ans+=x;
            k--;
        }
        return ans;
    }
};