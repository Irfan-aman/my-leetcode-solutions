class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n==1 ||n==2) return n;
        if((n&(n-1))==0) return 2*n;
        for(int i=n+1;i<2*n;i++){
            if((i&(i-1))==0) return i;
        }
        return -1;//never returned
    }
};