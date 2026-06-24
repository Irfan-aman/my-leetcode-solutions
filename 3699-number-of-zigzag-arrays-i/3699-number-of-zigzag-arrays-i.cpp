class Solution {
public:
    typedef long long ll;
    int MOD=1e9+7;
    int zigZagArrays(int n, int l, int r) {
        int m=r-l+1;
        ll dp[2001][2001][2];//DP Array
        for(int prevVal=1;prevVal<=m;prevVal++){//Base Case
            dp[n][prevVal][1]=1;
            dp[n][prevVal][0]=1;
        }
        for(int i=n-1;i>=0;i--){
            vector<ll> cumSum0(m+1,0);
            vector<ll> cumSum1(m+1,0);
            for(int val=1;val<=m;val++){
                cumSum0[val]=(cumSum0[val-1]+dp[i+1][val][0])% MOD;
                cumSum1[val]=(cumSum1[val-1]+dp[i+1][val][1])% MOD;
            }
            for(int prevVal=1;prevVal<=m;prevVal++){
                dp[i][prevVal][1]=(cumSum0[m]-cumSum0[prevVal]+MOD)% MOD;
                dp[i][prevVal][0]=cumSum1[prevVal-1];
            }
        }
        ll result=0;
        for(int startVal=1;startVal<=m;startVal++){
            result=(result+dp[1][startVal][1]) % MOD;
            result =(result + dp[1][startVal][0]) % MOD;
        }
        return result;
    }
};