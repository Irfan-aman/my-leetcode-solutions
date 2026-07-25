class Solution {
public:
    int maxProduct(int n) {
        int ans=0 , prev=n%10;n/=10;
        while(n){
            int dig=n%10;
            n/=10;
            ans=max(ans,prev*dig);
            prev=max(prev,dig);
        }
        return ans;
    }
};