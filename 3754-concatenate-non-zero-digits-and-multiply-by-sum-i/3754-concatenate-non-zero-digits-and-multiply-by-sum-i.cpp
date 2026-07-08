class Solution {
public:
    typedef long long ll;
    long long sumAndMultiply(int n) {
        ll x=0 , sum=0 ,mul10=1;
        while(n){
            int dig=n%10;
            if(dig) {
                x=mul10*dig +x;
                sum +=dig;
                mul10 *=10;
            }
            n /=10;
        }
        return x*sum;
    }
};