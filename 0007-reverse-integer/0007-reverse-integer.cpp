class Solution {
public:
    int reverse(int x) {
        int sign=1;
        long long n=x;
        if(x<0) {
            sign=-1;
            n*=-1;
        }
        long long ans=0;
        while(n){
            if(ans*10>INT_MAX || ans*10*sign<INT_MIN) return 0;
            ans=ans*10 + n % 10;
            n/=10;
        }
        return (int)ans*sign;
    }
};