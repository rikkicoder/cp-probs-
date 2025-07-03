#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
const int INF = 4e18;

int n;
vector<int> tree[100010];
int dp [100010][2];

void dfs(int node, int par){
    dp[node][0] = 1;
    dp[node][1] = 1;
    for (auto ch :tree[node]){
        if (ch != par){
            dfs(ch,node);
            dp[node][0] = (dp[node][0] * ((dp[ch][1])%mod))%mod;
            dp[node][1] = (dp[node][1] * dp[ch][0])%mod;
        }
    }
    dp[node][0] = (dp[node][0] + dp[node][1]) % mod;
}

signed main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n-1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1,0);
    int ans = dp[1][0];
    cout << ans%mod << '\n';
    return 0;
}