#include<bits/stdc++.h>
#define int long long
using namespace std;

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

int dps(int i,int sum){
    if (i == n){return 0;}
    if (dp[i][sum] != -1) return dp[i][sum];

    int ans = dps(i+1,sum);

    if (sum+weigh[i] <= w){
        ans = max(ans, val[i]+dps(i+1,sum+weigh[i]));
    }
    dp[i][sum] = ans;
    return dp[i][sum] ;
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >>n>>w;
    for (int i=0;i<n;i++){cin >> weigh[i] >> val[i];}
    memset(dp,-1,sizeof(dp));
    cout << dps(0,0)<<endl;

    
    return 0;
      
}






