#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;
const int mod = 1e9+7;

vi dp;
string s;
int n;

int rec(int idx,int last,vi & vis){
    if (i == n) return 1;
    if (dp[idx] != - 1) return dp[idx];
    int ans = 0;

}

void solve(){
    cin >> n;
    cin >> s;
    vi vis(n+1,0);
    dp.assign(n+1,-1);
    

}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //int t;cin >> t;while (t--)
    solve();
}