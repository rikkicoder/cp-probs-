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

int max(int a,int b){
    return (a>b) ? a :b;
}

int MOD = 1e9 +7;

double dp[3001][3001];
int n;
vector <double> p(3001);
double dps(int i,int heads){
    if (i == n){
        if (heads > n/2) return 1.0;
        else return 0;
    }

    if (dp[i][heads] != -1.0) return dp[i][heads];

    double ans = (p[i]*dps(i+1,heads+1))+((1-p[i])*dps(i+1,heads));
    return dp[i][heads] =ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >>n;
    for (int i=0;i<n;i++){cin >> p[i];}
    for(int i=0;i<3001;i++){
        for (int j=0;j<3001;j++){
            dp[i][j] = -1;
        }
    }
    cout << fixed << setprecision(10) << dps(0,0) <<endl;
    //cout << dps(0,0)<<endl;

    return 0;
      
}






