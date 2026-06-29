class Solution {
public:
    typedef long long ll;

    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        ll ans=0 , curr=1;
        for(int &x:nums){
            if(x<curr) continue;
            ll cnt = min( (ll)k , (ll)x - curr);
            ans += (curr+curr + cnt-1)*cnt/2; // sum of AP series = (2a+ (n-1)d) n/2
            k-=cnt;
            if(k==0) return ans;
            curr =x+1;;
        }
        ans+=(curr+curr+k-1)*k/2;
        return ans;
        
    }
};