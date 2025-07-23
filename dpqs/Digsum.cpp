#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;
const int mod = 1e9+7;

vector<vector<vi>> dp;
string s;
int n,d;

int rec(int idx, int edge, int sum){
    if(idx == n){return (sum == 0);}
    if (dp[idx][edge][sum] != - 1){return dp[idx][edge][sum];}
    int ans  =0;
    int lim = (edge == 0 ? 9 : s[idx]-'0');
    for (int i =0;i<=lim;i++){
        ans = (ans + rec(idx+1, (edge & ((s[idx]-'0') == i)),(sum+i)%d))%mod;
    }
    return dp[idx][edge][sum] = ans;
}

void solve(){
    cin >> s;
    n = s.size(); 
    cin >> d;
    dp.assign(n+1,vector<vi>(2,vi(d,-1)));
    cout << (rec(0,1,0)+mod-1)%mod  << '\n';
    // for (int i = 0;i<n;i++)
    //     for (int j =0;j<2;j++){
    //         cout << "dp["<<i<<"]["<<j<<"] = " <<dp[i][j]<<endl;
    //     }

}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //int t;cin >> t;while (t--)
    solve();
}