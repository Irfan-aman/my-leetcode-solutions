class Solution {
public:
    int myAtoi(string s) {
        int sign = 1, i = 0,n=s.size();
        long long ans = 0;
        while (i<n && s[i] == ' ')
            i++;
        if(i<n && (s[i]=='+' || s[i]=='-') ){
            sign=(s[i]=='-')?-1:1;
            i++;
        }
        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');
            if (sign==1 && ans > INT_MAX)
                return INT_MAX;
            else if (sign==-1 && -ans < INT_MIN)
                return INT_MIN;
            
            i++;
        }
        return ans*sign;
    }
};