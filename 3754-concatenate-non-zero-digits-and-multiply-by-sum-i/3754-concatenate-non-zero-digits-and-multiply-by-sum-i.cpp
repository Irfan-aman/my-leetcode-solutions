class Solution {
public:
    typedef long long ll;
    long long sumAndMultiply(int n) {
        ll x=0 , sum=0;
        string st=to_string(n);
        for(char &ch:st){
            int dig=ch-'0';
            if(dig) {
                x=x*10 + dig;
                sum +=dig;
            }
            n /=10;
        }
        return x*sum;
    }
};