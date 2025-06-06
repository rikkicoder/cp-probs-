#include<bits/stdc++.h>
#include <vector>
#include <map>
#include <algorithm>
//#define int long long
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

int dp[100001];

int dps(int h[],int n,int i){
    if ( i == n-1) return 0;
    if (dp[i] != -1) return dp[i];

    int ans = dps(h,n,i+1)+abs(h[i]-h[i+1]);

    if(i <= n-3){
        ans = min(ans,dps(h,n,i+2)+abs(h[i]-h[i+2]));
    }
    dp[i] = ans;
    return ans;

}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >>n;
    int h[n];
    for (int i=0;i<n;i++){cin >> h[i];}
    memset(dp,-1,sizeof(dp));

    cout << dps(h,n,0) << endl;
    return 0;
      
}






