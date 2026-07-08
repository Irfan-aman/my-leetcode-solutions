class Solution {
public:
    int MOD= 1e9+7;
    typedef long long ll;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<ll> prefSum(n,0);
        vector<ll> prefX(n,0);
        vector<int> prefDig(n,0);
        vector<ll> pow10(n+1,0);
        pow10[0]=1;
        for(int i=1;i<=n;i++){
            pow10[i]=pow10[i-1]*10 % MOD;
        }
        int firstDig=s[0]-'0';
        prefSum[0]=firstDig; prefX[0]=firstDig;
        prefDig[0]= (firstDig==0)?0:1;
        for(int i=1;i<n;i++){
            int dig=s[i]-'0';
            if(dig){
                prefX[i]= (prefX[i-1] *10 +dig) % MOD;
            }else prefX[i]= prefX[i-1] ;
            prefSum[i]=prefSum[i-1]+dig;
            prefDig[i]=prefDig[i-1] + ((dig==0)?0:1) ;
        }
        vector<int> ans;
        for(auto &q:queries){
            int l=q[0] , r=q[1];
            if(l-1>=0){
                int k=prefDig[r]-prefDig[l-1];//no. of digits
                int sum=prefSum[r]-prefSum[l-1];
                ll x= (prefX[r] - (prefX[l-1]* pow10[k])% MOD +MOD)% MOD;
                ll res= (x*sum ) % MOD;
                ans.push_back( res);
            }else { 
                ll res=(prefSum[r]*prefX[r])% MOD;
                ans.push_back(res % MOD);
            }
        }
        return ans;
    }
};