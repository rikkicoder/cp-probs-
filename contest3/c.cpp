#include<bits/stdc++.h>
#include <vector>
#include <map>
#include <algorithm>
#define int long long
using namespace std;

int MOD =  998244353;

int min (int a,int b){
    return (a>b) ? b :a;
}

int dp[200001][2];

int rec(int a[],int i,int n,int liars,int prev){
    if (i == n){return 1;cout<<"done\n";}
    if (dp[i][prev] != -1) return dp[i][prev];

    if (prev == 0){
        if(a[i] != liars) {dp[i][prev] = 0;return 0;}
        else {
            int ans = rec(a,i+1,n,liars+1,1);
            dp[i][prev] = ans ;return ans;           
        }
    }
    else{
        if (a[i] != liars)
        {
            int ans = rec(a,i+1,n,liars+1,0);
            dp[i][prev] = ans; return ans;
        }
        else {
            int ans1 = rec(a,i+1,n,liars,1);
            int ans2 = rec(a,i+1,n,liars+1,0);
            dp[i][prev] = ans2+ans1; return ans2+ans1;
        }
    }
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >>t;
    while (t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++){cin >>a[i];}
        memset(dp,-1,sizeof(dp));
        if (a[0] == 0) cout<<rec(a,1,n,0,1)+rec(a,1,n,1,0)<<endl;
        else cout << rec(a,1,n,1,0)<<endl;
        
       
    }
    return 0;
      
}






