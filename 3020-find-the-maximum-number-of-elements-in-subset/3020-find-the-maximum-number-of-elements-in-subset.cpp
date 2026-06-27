class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int &x:nums) mp[x]++;
        int one=0;
        int ans=0;
        if(mp.count(1)){
            one=mp[1];
            mp.erase(1);
            ans=one-((one%2==0)?1:0);
        }
        for(auto &it:mp){
            long long n=it.first;
            int cnt=1;
            while(n*n<INT_MAX && mp.count(n*n) && mp[n]>1){
                cnt++;
                n*=n;
                if(mp[n]>1){
                    continue;
                }else break;
            }
            ans=max(ans,2*cnt-1);
        }
        return ans;
    }
};