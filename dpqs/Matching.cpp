#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;

vector<vector<int>> dp;
int n;
vector<vector<int>> a;

int rec(int i, int st){
    if (i == n) { if (st == ((1<<n)-1)) return 1;else return 0;}
    if (dp[i][st] != -1) return dp[i][st];

    int ans = 0;
    for (int j = 0;j < n;j++){
        if (a[i][j] && !(st & (1 << j))) ans = (ans+rec(i+1,(st|(1<<j))))%mod;
    }

    return dp[i][st] = (ans%mod);
}

void solve(){
    cin >> n;
    a.assign(n,vector<int>(n,0));
    dp.assign(n+1,vector<int>((1<<n),-1));
    for (int i = 0;i<n;i++){
        for (int j =0;j<n;j++){
            cin >> a[i][j];
        }
    }
    cout << rec(0,0) <<endl;

}

signed main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //int t;cin >>t;while(t--)
    solve();
    return 0;
}