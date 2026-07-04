class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto &road:roads){
            int a=road[0] ,b=road[1] ,dist=road[2];
            adj[a].push_back({b,dist});
            adj[b].push_back({a,dist});
        }
        vector<bool> vis(n+1,false);
        vis[1]=true;
        queue<int> q;
        q.push(1);
        int ans=INT_MAX;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto &[v,dist]:adj[u]){
                ans=min(ans,dist);
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};