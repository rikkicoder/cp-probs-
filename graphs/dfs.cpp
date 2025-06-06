#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fo(n) for (int i=0;i<n;i++)

vector<vector<int>> graph;
vector <int> vis;

void dfs(int u){
    vis[u] =1;
    for (auto v :grpah[u]){
        if (!vis[v]){
            dfs(v);
        }
    }
}
signed main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    graph.resize(n+1,vector<int>());
    vis.resize(n+1,0);
    for (int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int no_comp = 0;
    for (int i= 1;i<=n;i++){
        if (!vis[i]){
            dfs(i);
            no_comp++;
        }
    }
    cout << no_comp <<endl; 
    
    return 0;
}