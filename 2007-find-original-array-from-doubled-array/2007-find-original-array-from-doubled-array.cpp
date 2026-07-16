class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        if( (n&1) ==1) return {};
        unordered_map<int,int> mp;
        for(int &x:changed) mp[x]++;
        sort(changed.begin(),changed.end());
        vector<int> orig;
        if( (mp[0] & 1) ==1 ) return {};
        for(int i=0;i<n;i++){
            if(mp[changed[i]]==0) continue;
            if( mp[changed[i]*2]==0 ) return {};
            orig.push_back(changed[i]);
            mp[changed[i]]--;
            mp[changed[i]*2]--;
        }
        return orig;
    }
};