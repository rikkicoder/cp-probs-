#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> tree[200100];
int val [200010];
int dep[200010];
int par[200100];
int parl[200010][20];
bool isLeaf[200100];
int numChild[200010];
int subtreeSz[200100];
int dp[200100][20];
int prefix[200010];
int partial[200010];

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
            dfs(child,node,depth+1);
            subtreeSz[node] += subtreeSz[child];  
        }
    }
}


void solve(){
    int n;
    cin >> n;
    val[0] =0;
    for(int i =1;i<=n;i++){
        tree[i].clear();
        val[i] =0;
    }
    for (int i =2;i<=n;i++){
        int a;cin >> a; 
        tree[a].push_back(i);
        tree[i].push_back(a);
    }
    dfs(1,0,0);
    for(int i =1;i<=n;i++){
        cout << subtreeSz[i]-1 << " ";
    }
    cout << '\n';
}
signed main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int t; cin >>t; while(t--) 
    solve();
    return 0;
}