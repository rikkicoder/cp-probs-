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

int gcd(int a, int b){
    if (a < b)swap(a,b);
    if (b==0)return a;
    return gcd(b,a%b);
}
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

void dfs_lca(int node, int parent,int d){
    parl[node][0] = parent;
    dep[node] =d;
    dp[node][0] =val[node]; // when you go up you have to include all the nodes before it  
    for (int i =1;i<20;i++){
        parl[node][i] = parl[parl[node][i-1]][i-1];
        dp[node][i] = gcd(dp[node][i-1],dp[parl[node][i-1]][i-1]);
        // as we are doing a dfs, parents are always completed.
    }
    for (auto child : tree[node]){
        if (child != parent){
            dfs_lca(child,node,d+1);
        }
    }
}

int lca (int u, int v){
    if (dep[u] < dep[v]){swap(u,v);}
    for (int i =19;i>=0;--i){
        if ((dep[u]-dep[v])&(1<<i)){
            u = parl[u][i];
        }
    }
    if (u == v) return v;
    for(int i =19;i>=0;--i){
        if (parl[u][i] != parl[v][i]){
            u = parl[u][i];
            v= parl[v][i];
        }
    }
    return parl[u][0];
}

int find_gcd(int u, int v){
    if (dep[u] < dep[v])swap(u,v);
    int ans =0;
    for (int i =19;i>=0;--i){
        if ((dep[u]-dep[v])&(1<<i)){
            ans  = gcd(ans,dp[u][i]);
            u = parl[u][i];
        }
    }
    if (u == v) return gcd(ans,val[u]);
    for (int i = 19;i>=0;--i){
        if (parl[u][i] != parl[v][i]){
            ans = gcd(ans,dp[v][i]);
            v = parl[v][i];
            ans = gcd(ans,dp[u][i]);
            u = parl[u][i];
        }
    }
    return gcd(ans, val[parl[u]][0]);
}
void dfs_prefix(int node,int parent,int d,int val){
    par[node] = parent;
    dep[node] = d;
    prefix[node] = val+prefix[parent];
    for(auto child : tree2[node]){
        if (child.f != parent){
            dfs_prefix(child.f,node,d+1,child.s);
        }
    }
}

void addX(int u,int v, int x){
    partial[u] += x;
    partial[v] += x;
    int lc = lca(u,v);
    partial[lc] -= x;
    partial[parl[lc][0]] -= x; // [u-lc) + [v-lc] = [u-v] this is for when you count node wise;
    // else you just do partia[lc] -= 2 if edge wise 
}
void pushAll(int node, int papa){
    for (auto child : node){
        if (child != papa) pushAll(child,node);
    }
    //we are pushing up , so parent += every child
    partial[parl[node][0]] += partial[node];
}

int get_pathlen(int u, int v){
    return prefix[u] + prefix[v] - 2*prefix[lca(u,v)]; // if edge weights are given
}
void solve(){
    int n;
    cin >> n;
    val[0] =0;
    for(int i =1;i<=n;i++){
        tree[i].clear();
        val[i] =0;
    }
    for (int i =0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1,0,0);
}
signed main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >>t; while(t--) solve();
    return 0;
}