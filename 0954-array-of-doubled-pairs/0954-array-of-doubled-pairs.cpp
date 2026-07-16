class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> mp;
        for(int &x:arr) mp[x]++;
        int cnt=0;
        sort(arr.begin(),arr.end(),[](int a,int b){
            return abs(a)<abs(b);
        });
        for(int &x:arr){
            if(mp[x]==0) continue;
            if(mp[2*x]==0) return false;
            mp[x]--; mp[2*x]--;
            cnt++;
        }
        return cnt==n/2;
    }
};