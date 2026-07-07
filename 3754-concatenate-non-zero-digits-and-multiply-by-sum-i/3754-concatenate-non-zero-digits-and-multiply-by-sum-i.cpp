class Solution {
public:
    typedef long long ll;
    ll reverseInt(int x){
        ll rev=0;
        while(x){
            rev =rev*10 + x%10;
            x/=10;
        }
        return rev;
    }
    long long sumAndMultiply(int n) {
        ll x=0 , sum=0;
        while(n){
            int dig=n%10;
            if(dig) {
                x=x*10 + dig;
                sum +=dig;
            }
            n /=10;
        }
        x=reverseInt(x);
        return x*sum;
    }
};