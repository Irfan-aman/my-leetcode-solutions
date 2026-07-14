class Solution {
public:
    int MOD=1e9+7;
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(maxi+1,vector<int>(maxi+1,0)));
        for(int i=1;i<=maxi;i++){
            for(int j=1;j<=maxi;j++){
                if(i==j)dp[n][i][j]=1;
                else dp[n][i][j]=0;
                
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=maxi;j>=0;j--){
                for(int k=maxi;k>=0;k--){
                    dp[i][j][k] =(0LL+dp[i+1][j][k]+dp[i+1][__gcd(j,nums[i])][k] +dp[i+1][j][__gcd(k,nums[i])])%MOD;
                }
            }
        }
        return dp[0][0][0];
    }
};