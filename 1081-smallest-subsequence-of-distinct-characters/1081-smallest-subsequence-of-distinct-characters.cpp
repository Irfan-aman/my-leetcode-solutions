class Solution {
public:
    string smallestSubsequence(string s) {
        vector<bool> seen(26,false);
        vector<int> lastIdx(26,-1);
        for(int i=0;i<s.size();i++){
            lastIdx[s[i]-'a']=i;
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            if(seen[s[i]-'a']) continue;
            while(!ans.empty() && ans.back()>s[i] && lastIdx[ans.back()-'a']>i) {
                seen[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            seen[s[i]-'a']=true;
        }
        return ans;
    }
};