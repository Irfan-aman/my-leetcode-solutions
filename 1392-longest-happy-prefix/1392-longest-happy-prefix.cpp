class Solution {
public:
    void lpsCode(string &s,vector<int> &LPS){
        LPS[0]=0;
        int i=1 , length=0;
        while(i<s.size()){
            if(s[i]==s[length]){
                length++;
                LPS[i++]=length;
            }else{
                if(length!=0){
                    length = LPS[length-1];
                }else{
                    LPS[i++]=0;
                }
            }
        }
    }
    string longestPrefix(string s) {
        int n=s.size();
        vector<int> LPS(n,0);
        lpsCode(s,LPS);
        return s.substr(0,LPS[n-1]);
    }
};