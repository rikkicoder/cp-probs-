#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fo(n) for (int i=0;i<n;i++)

int dp[3001][3003][2];
int a[3002];
int rec(int l, int r, int i){
    if (l > r) return 0;
    if (dp[l][r][i] != -1) return dp[l][r][i];
    int ans  = 0;
    if (i == 0){
        ans = max(rec(l+1,r,1)+a[l], rec(l,r-1,1)+a[r]);
    }
    else {
        ans = min(rec(l+1,r,0)-a[l], rec(l,r-1,0)-a[r]);
    }
    return dp[l][r][i] = ans;
}


void solve(){
    int n;
    cin >> n;
    for (int i = 0; i< n;i ++){
        cin >> a[i];
        for (int j =0; j<n;j++){
            dp[i][j][0] =-1;
            dp[i][j][1] =-1;
        }
    }
    
    cout << rec(0,n-1,0) <<endl;

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    t= 1;
    // cin >>t;
    while (t--){
       solve();
    }
    return 0;
}
