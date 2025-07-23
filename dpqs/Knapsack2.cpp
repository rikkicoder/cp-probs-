#include<bits/stdc++.h>
#include <vector>
#include <map>
#include <algorithm>
#define int long long
using namespace std;
const int INF = 4e18;
void print (int i){
    if (i) cout << "YES\n";
    else cout << "NO\n";
}

int divi(int a,int b){
    return (a % b == 0) ? ((a/b)) : ((a/b))+1;
}

int min (int a,int b){
    return (a>b) ? b :a;
}
int max(int a,int b){return (a>b) ? a :b;}
int n,w;
int weigh[101],val[101];

int dp[101][100001];

int dps(int i,int tval){
    if (i == n){return (tval == 0 ? 0 : INF);}
    if (dp[i][tval] != -1) return dp[i][tval];
    int ans = dps(i+1,tval);

    if (tval >= val[i]) ans = min(ans,weigh[i]+dps(i+1,tval-val[i]));
    
    return dp[i][tval] =ans; 
        

}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> w;
    for (int i=0;i<n;i++){cin >> weigh[i] >> val[i];}
    
    int ans = 0;
    memset(dp,-1,sizeof(dp));

    dps(0,1e5);
    for (int i=0;i<=1e5;i++){
        if (dp[0][i] <= w) ans = max(ans,dp[0][i]);
    }

    cout << ans <<endl;

    
    return 0;
      
}






