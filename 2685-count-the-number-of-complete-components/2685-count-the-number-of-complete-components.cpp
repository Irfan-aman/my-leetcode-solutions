class Solution {
public:
    void dfs(int src,unordered_map<int,vector<int>> &adj,vector<bool> &vis,int &v,int &e){
        vis[src]=true;
        v++;
        e+=adj[src].size();
        for(auto &nbr:adj[src]){
            if(!vis[nbr]){
                dfs(nbr,adj,vis,v,e);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int v =0, e=0;
                dfs(i,adj,vis,v,e);
                if(v*(v-1)/2 == e/2) ans++;
            }
        }
        return ans;
    }
};