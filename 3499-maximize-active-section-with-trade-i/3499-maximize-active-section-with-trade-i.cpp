class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        vector<int> inactive;//continuous inactive section
        int active=count(s.begin(),s.end(),'1');

        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                int start=i;
                while(i<n && s[i]=='0')i++;
                inactive.push_back(i-start);
            }
        }
        int cnt=0; //store max pair  
        for(int i=1;i<inactive.size();i++){
            cnt=max(cnt,inactive[i]+inactive[i-1]);
        }
        return cnt+active;
    }
};