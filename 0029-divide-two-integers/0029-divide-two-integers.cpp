class Solution {
public:
    typedef long long ll;
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        bool sign=true;
        if( (dividend<=0 && divisor>0) || (dividend>=0 && divisor<0)) sign =false;
        ll n=abs((ll)dividend);
        ll d=abs((ll)divisor);
        ll ans=0;
        while(n>=d){
            int cnt=0;
            while(n >= d<<(cnt+1)){
                cnt++;
            }
            ans+=1ll<<cnt;
            n-=d<<cnt;
        }
        if(ans>INT_MAX && sign) return INT_MAX;
        if(ans>INT_MAX && !sign) return INT_MIN;
        return sign?ans:ans*-1;
    }
};