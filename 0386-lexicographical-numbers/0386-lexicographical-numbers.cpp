class Solution {
public:
    void solve(int num,int n,vector<int> & ans){
        if(num>n) return;
        ans.push_back(num);
        for(int append=0;append<=9;append++){
            int newNum=num*10+append;
            if(newNum>n) return;
            solve(newNum,n,ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1;i<=9 && i<=n;i++){
            solve(i,n,ans);
        }
        return ans;
    }
};