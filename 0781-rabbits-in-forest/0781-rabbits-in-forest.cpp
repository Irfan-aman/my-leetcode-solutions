class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n=answers.size();
        unordered_map<int,int> mp;
        for(int &x:answers) mp[x]++;
        int ans=0;
        for(auto &it:mp){
            int f=it.second;
            int groupSize=it.first+1;
            int groups=(f+groupSize-1)/groupSize;
            ans += groupSize * groups;
        }
        return ans;
    }
};