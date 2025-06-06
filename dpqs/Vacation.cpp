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

int max(int a,int b){
    return (a>b) ? a:b;
}

int n;
int a[100001],b[100001],c[100001];

int dp[100001][4];

int dps (int i,int flag){
    if (i > n-1) return 0;
    if (dp[i][flag] !=  -1) return dp[i][flag];

    long long int ans = 0;

    if (flag != 1){ ans = max (ans,a[i]+dps(i+1,1));}
    if (flag != 2){ ans = max(ans,b[i]+dps(i+1,2));}
    if (flag != 3){ans = max(ans, c[i]+dps(i+1,3));}

    dp[i][flag] = ans;
    return ans;
}



int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin >>n;
    for (int i=0;i<n;i++){cin >> a[i] >> b[i] >> c[i];}
    memset(dp,-1,sizeof(dp));
    cout << dps(0,0) <<endl;
    
    return 0;
      
}






