#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mp make_pair
#define f first
#define s second
using pi = pair<int,int>;

void solve(){
    int n,m;
    cin >>n >>m;
    vector<vector<int>> g;
    g.resize(n+1);
    for (int i =0;i<m;i++){
        int u,v;
        cin >> u >>v;
        g[u].push_back(v);
    }
     

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}