#include <bits/stdc++.h>
using namespace std;
#define int long long 

int n,k;
vector<int> a;
vector<bool> dp;
vector<bool> vis;

bool winornot (int left){
    if (left == 0) return false;
    if (vis[left]) return dp[left];
    vis[left] =1;
    for(int i =0;i<n;i++){
        if (left >= a[i] && winornot(left-a[i]) == false) return dp[left] = true;
    }
    return dp[left] = false;
}

void solve(){
    cin >> n >> k;
    a.assign(n,0);
    dp.assign(k+1,0);
    vis.assign(k+1,0);
    for (int i =0;i<n;i++){cin >> a[i];}
    cout << (winornot(k) ? "First" : "Second") << "\n";

}

signed main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //int t;cin >>t;while(t--)
    solve();
}