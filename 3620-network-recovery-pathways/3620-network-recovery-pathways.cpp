class Solution {
public:
    typedef long long ll;
    typedef pair<long long,int> P;
    bool check(int mid,unordered_map<int,vector<vector<int>>> &adj,int n,long long k){
        vector<ll> res(n,LLONG_MAX);
        priority_queue<P,vector<P>,greater<P>> pq;
        res[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            int node=pq.top().second;
            ll d=pq.top().first;
            pq.pop();
            if(d>k) continue;
            if(res[node]<d) continue;
            if(node==n-1) return true;
            for(auto &vec:adj[node]){
                int nbr=vec[0];
                int cost=vec[1];
                if(cost<mid) continue;
                if(d+cost<res[nbr]){
                    res[nbr]=d+cost;
                    pq.push({d+cost,nbr});
                }
            }
        }
        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        if(!online[0] || !online[n-1]) return -1;
        unordered_map<int,vector<vector<int>>> adj;//adjacency list
        int l=INT_MAX , r=0;
        for(auto &e:edges){
            int u=e[0] , v=e[1] , cost=e[2];
            if(!online[u] || !online[v]) continue;
            adj[u].push_back({v,cost});
            l=min(l,cost);
            r=max(r,cost);
        }
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid,adj,n,k)){
                ans=mid;
                l=mid+1;
            }else r=mid-1;
        }
        return ans;
    }
};