class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int i=0 ,j = 0 , n=s.size();
        int ans=0;
        int maxFreq=0;
        while(j<n){
            mp[s[j]]++;
            maxFreq=max(maxFreq,mp[s[j]]);
            if((j-i+1)-maxFreq <= k) {
                ans=max(ans,j-i+1);
            }else{
                if(mp[s[i]]==maxFreq) maxFreq--;
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};