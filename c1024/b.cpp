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
    int n;
    cin >>n ;
    vector <int> a(n);
    for (int &i :a){cin >> i;}
    int nc =0,c =0;
    for (int i =1;i<n;i++){
        if (abs(a[i]) > abs(a[0])) c++;
        else nc++;
    }

    if ((nc > divi(n,2))) cout << "NO\n";
    else cout << "YES\n";

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