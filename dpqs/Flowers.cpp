#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
const int INF = 4e18;
const int mod = 1e9+7;
using pi = pair<int,int>;

int n;
vector<int> a,h;
vector<vector<int>> dp;

int rec(int i,int taken){
    if(i <0) return 0;
    if (dp[i][taken] != -1) return dp[i][taken];
    int ans =0;
    if (taken){
        ans= a[i];
        for(int j =i-1;j>=0;--j){
            if (h[j] < h[i]) ans= max(ans,a[i]+rec(j,1));
        }
    }
    else{
        ans = max(rec(i-1,1),rec(i-1,0));
    } 

    return dp[i][taken] = ans;
    
}

void solve(){
    cin >> n;
    a.assign(n,0);
    h.assign(n,0);
    dp.assign(n+1,vector<int>(2,-1));
    vector<int> pre_max(n+1,0);
    dp[0][0] = 0, dp[0][1] =a[0], pre_max[0] = dp[0][1];
    for (int i =0;i<n;i++) cin >> h[i];
    for (int i =0;i<n;i++) {cin >> a[i];summ+=a[i];}\
    for(int i = 1;i<n;i++){
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
        dp[i][1] = 
    }

    cout << rec(n,0) << "\n";
    
}
signed main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //int t;cin >>t;while(t--)
    solve();
    return 0;
}