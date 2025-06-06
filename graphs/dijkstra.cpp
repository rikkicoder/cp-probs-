#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fo(n) for (int i=0;i<n;i++)
#define F first
#define S second

vector<vector<pair<int,int>>> g;
vector <int> vis;
vector<int> dist;
const int INF = 1e18;

class prioritize{
    public : bool operator()(pair<int,int> a, pair<int,int> b){
        return a.S > b.S; // min heap based on the second element
    }
};
int n,m;

void dijsktra(int src){
    dist[src] = 0;
    priority_queue<pair<int,int>> q; 
    q.push({0,src});
    while(!q.empty()){
        auto p = q.top();
        q.pop();
        if (vis[p.S]) continue;
        vis[p.S] =1;
        for (auto v : g[p.S]){
            if (dist[v.F] > v.F + dist[p.S]){
                dist[v.F] = v.F + dist[p.S];
                q.push({-dist[v.F],v.F});
            }
        }
    }


}


signed main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin >> n >> m;
    g.resize(n+1,vector<pair<int,int>>());
    dist.assign(n+1,INF);
    vis.assign(n+1,0);
    for (int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dijsktra(1);
    
    return 0;
}