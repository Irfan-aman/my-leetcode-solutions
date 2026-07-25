class Solution {
public:
    int maxProduct(int n) {
        int maxProd=0 , maxDig=n%10;
        n/=10;
        while(n){
            int dig=n%10;
            n/=10;
            maxProd=max(maxProd,maxDig*dig);
            maxDig=max(maxDig,dig);
        }
        return maxProd;
    }
};