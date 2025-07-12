#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mod = 1e9+7;


void solve(){
    int n,k;
    cin >> n >> k;
    int a[n];
    for (int &i : a) cin >> i;
    vector<vector<int>> dp (n+1, vector<int>(k+1));
    vector<vector<int>> pre(n+1,vector<int>(k+2));
    for (int j =0;j<=k;j++){
        dp[0][j] = (j <=a[0] ? 1 :0);
    }
    pre[0][0] =0;
    for (int i = 1;i<=k+1;i++){
        pre[0][i] = (pre[0][i-1]+dp[0][i-1])%mod;
    }
    
    for (int i =1;i<n;i++){
        pre[i][0] =0;
        for(int j = 0;j<=k;j++){
            dp[i][j] = (pre[i-1][j+1]-pre[i-1][max(0LL,j-a[i])] +mod)%mod;
            pre[i][j+1]= (pre[i][j]+dp[i][j])%mod;
        }
    }
    cout << dp[n-1][k] << endl;

}

signed main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //int t;cin >>t;while(t--)
    solve();
}