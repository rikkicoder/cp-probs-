#include<bits/stdc++.h>
#define int long long
#define fo(n) for (int i=0;i<n;i++)
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
int max(int a, int b){
    return (a>b) ?a: b;
}

void solve(){
    int n,m,p,q;
    cin >>n >> m >> p >> q;
    if (n % p != 0){
        cout << "YES\n";
    }
    else{
        if ((n/p)*q == m) cout << "YES\n";
        else cout << "NO\n";
    }
    return;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}