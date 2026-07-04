class Solution {
public:
    void dfs(int u,unordered_map<int,vector<pair<int,int>>> &adj,vector<bool> &vis,int &ans){
        vis[u]=true;
        for(auto &[v,dist]:adj[u]){
            ans=min(ans,dist);
            if(!vis[v]){
                vis[v]=true;
                dfs(v,adj,vis,ans);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto &road:roads){
            adj[road[0]].push_back({road[1],road[2]});
            adj[road[1]].push_back({road[0],road[2]});
        }
        vector<bool> vis(n+1,false);
        int ans=INT_MAX;
        dfs(1,adj,vis,ans);
        return ans;
    }
};