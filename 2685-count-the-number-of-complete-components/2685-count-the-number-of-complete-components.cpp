class Solution {
public:
    void bfs(int src,vector<vector<int>> &adj,vector<bool> &vis,int &v,int &e){
        queue<int> q;
        q.push(src);
        vis[src]=true;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            v++;e +=adj[u].size();
            for(auto &nbr:adj[u]){
                if(!vis[nbr]){
                    vis[nbr]=true;
                    q.push(nbr);
                }
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int v =0, e=0;
                bfs(i,adj,vis,v,e);
                if(v*(v-1)== e) {//for complete comp. => e=v*(v-1)/2 ,but bcz edge of all node will be counted twice so we have to divide e be 2 also so that comes out e=v*(v-1)
                    ans++;
                }
            }
        }
        return ans;
    }
};