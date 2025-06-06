#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fo(n) for (int i=0;i<n;i++)

int arr[505];
int dp [502][502];
int pre[502];

int rec(int l, int r){
    if (l == r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    int ans  = 0;
    for (int i =l ;i<r;i++){
        ans = max(ans, rec(l,i)+rec(i+1,r) + (pre[r]-pre[i])*(pre[i]-pre[l-1]));
    }
    return dp[l][r] = ans;
}


void solve(){
    int n;
    for (int i = 0; i< n;i ++){cin >> arr[i];}
    memset(dp,-1,sizeof(dp));
    pre[0] =arr[0];
    for (int i =1;i<n;i++){
        pre[i] = arr[i]+pre[i-1];
    }
    cout << rec(0,n-1) <<endl;

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >>t;
    while (t--){
       solve();
    }
    return 0;
}
