#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
int a[401];
int pre[402];
vector<vector<int>> dp;
int cost(int l, int r){
    if (l >= r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    int ans =4e18;
    for (int k = l;k < r;k++){
        ans = min(ans,cost(l,k)+cost(k+1,r)+pre[r+1]-pre[l]);
        //if (ans == cost(l,k)+cost(k+1,r)+(pre[r+1]-pre[l])) cout << "(" << l << "," << k << ") is better where end is " << r  << endl;
    }
    return dp[l][r] = ans;
}

void solve(){
    cin >> n;
    dp.assign(n+1,vector<int>(n+1,-1));
    for (int i =0;i<n;i++){cin >> a[i];}
    pre[0] = 0;
    for (int i = 1;i<=n;i++){
        pre[i] = pre[i-1]+a[i-1];
    }
    cout << cost(0,n-1) <<"\n";

}

signed main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //int t;cin >>t;while(t--)
    solve();
    return 0;
}