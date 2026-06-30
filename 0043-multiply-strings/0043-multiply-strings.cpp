class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        int n=num1.size();
        int m=num2.size();
        vector<int> ans(n+m,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int a=num1[i]-'0';
                int b=num2[j]-'0';
                int mul=a*b;
                int sum=ans[i+j+1]+mul;
                ans[i+j+1]=sum%10;
                ans[i+j] +=sum/10;
            }
        }
        string res="";
        int i=0;
        while(i<ans.size() && ans[i]==0) i++;
        while(i<ans.size()){
            res.push_back(ans[i++]+'0');
        }
        return res;
    }
};