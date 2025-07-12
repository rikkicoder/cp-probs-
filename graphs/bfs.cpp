#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fo(n) for (int i=0;i<n;i++)
const int INF = 1e18;

vector<vector<int>> graph;
vector <int> vis;
vector <int> dis;
void bfs(int src){
    queue<int> q;
    //vis[src] =1;
    dis[src] = 0;
    q.push(src);
    while (!q.empty()){
        int x = q.front();
        q.pop();
        if (vis[x]) continue;
        vis[x] =1;
        cout << x << " ";
        for (auto v : graph[x]){
            if (dis[v] > dis[x] +1){
                dis[v] = dis[x] +1;
                q.push(v);
            }
        }    
    }
}
vector <vector <pair<int,int>>> graph01;
vector <int> vis01;
vector <int> dis01;
void bfs01(int src){
    deque<int> q;
    //vis01[src] =1;
    dis01[src] = 0;
    q.push_front(src);
    while (!q.empty()){
        int x =q.front();
        q.pop_front();
        if (vis[x]) continue;
        vis[x] =1;
        cout << x << " ";
        for (auto v : graph01[x]){
            int n = v.first;
            int cost = v.second;
            if (dis[n]> dis[x] + cost){
                dis[n] = dis[x] +cost;
                if(cost == 0){q.push_front(n);}
                else {q.push_back(n);}
            }
        }
    }
}

void djisktra(int src){
    priority queue<pair<int,int>> q;
    q.push({0,src});
    dis[src] = 0;
    while (!q.empty()){
        int x = q.top(second);
        int d = -1 * q.top().first;
        q.pop();
        if (vis[x]) continue;
        vis[x] =1;
        cout << x << " ";
        for (auto v :graph01[x]){
            if (dis[v.first] > d + v.second){
                dis[v.first] = d + v.second;
                q.push({-1 * dis[v.first],v.first});
            }
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
    dis.resize(n+1,INF);
    for (int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int src;
    cin >> src;
    int no_comp = 0;
    bfs(src);
    for (int i = 1; i <=n;i++){
        cout << i << " : " << dis[i] << endl;
    }

    
    
    return 0;
}