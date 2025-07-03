#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;
using pi = pair<int, int>;
const int INF = 4e18;


int n,k;
vector<pi> tree[300030];
vi nos[300001];
int val[300010];

void dfs(int node , int par){
    
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i =1;i<=n;i++){
        cin >> nos[i];
    }
    for(int i =0;i <n-1;i++){
        int a,b,c;
        cin >> a >> b >> c;
        tree[a].push_back({b,c});
        tree[b].push_back({a,c});
    }

    return 0;
}