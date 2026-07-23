class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n==1 ||n==2) return n;
        if((n&(n-1))==0) return 2*n;
        int ans=1;
        while(ans<=n){
            ans<<=1;//ans=ans*2; 1,2,4,8,16,.....
        }
        return ans;
    }
};