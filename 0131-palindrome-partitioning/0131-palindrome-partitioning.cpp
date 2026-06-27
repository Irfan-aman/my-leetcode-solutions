class Solution {
public:
    bool isPal(string str){
        int st=0,end=str.size()-1;
        while(st<=end){
            if(str[st]==str[end]){
                st++;end--;
            }else return false;
        }
        return true;
    }
    void solve(string &s,int idx,vector<string> &strs,vector<vector<string>> &ans){
        if(idx==s.size()){
            ans.push_back(strs);
            return;
        }
        string str="";
        for(int i=idx;i<s.size();i++){
            str+=s[i];
            if(isPal(str)){
                strs.push_back(str);
                solve(s,i+1,strs,ans);
                strs.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> strs;
        solve(s,0,strs,ans);
        return ans;
    }
};