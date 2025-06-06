#include <bitse/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second

vector<vector<pair<int,int>> g;
vector<int> vis;
vector <int> dist;
vector <pair<pair<int,int>,int>>> edges;
const int INF = 1e18;

signed main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int n,m;
    cin >> n >> m;
    g.resize(n+1,vector<pair<int,int>>());
    vis.resize(n+1,0);
    dist.assign(n+1,INF);
    
    for (int i = 0; i < m; i++){
        int u,v, d;
        cin >> u >> v >> d;
        g[u].push_back({v,d});
        edges.push_back({{u,v},-d});
    }
    dist[1] = 0;
    for (int i =1;i<n;i++){
        for (auto e : edges){
            int u =e.F.F,v = e.F.S, d =e.S;
            if (dist[u] != INF && dist[v] > dist[u]+d){
                dist[v] = dist[u] +d;
            }
        }
    }
    int flag = 0;
    for (auto e : edges){
        int u =e.F.F,v = e.F.S, d =e.S;
            if (dist[u] != INF && dist[v] > dist[u]+d){
                flag = 1;
                break;
            }
    }
    if (flag) cout << -1 <<endl;
    else{
        int min_ = INF;
        for (int i =1;i<=n;i++){
            min_ = min(min_,dist[i]);
        }
        cout << min_<<endl;
    }
}