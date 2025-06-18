#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> tree[100100];
int dep[100010];
int par[100100];
bool isLeaf[100100];
int numChild[100010];
int subtreeSz[100100];

void dfs(int node,int parent, int depth){
    dep[node] = depth;
    par[node] = parent;
    numChild[node] =0 ;
    subtreeSz[node] =1;
    isLeaf[node] =true;
    for (auto child : tree[node]){
        if (child != parent){
            numChild[node]++;
            isLeaf[node] =false;
            dfs(child,parent,depth+1);
            subtreeSz[node] += subtreeSz[child];  
        }
    }
}

void solve(){
    int n;
    cin >> n;
    for (int i =0;i<n-1;i++){
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0,0);
}
signed main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}