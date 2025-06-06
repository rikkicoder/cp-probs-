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
    cin >>n;
    vector<int> b;
    for (int i =0;i <n-2;i++){int h; cin >> h; b.push_back(h);}
    if (n >= 3){
    for (int i=0;i<n-4;i++){
        if (b[i] && !b[i+1] && b[i+2]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    }
    else {cout << "YES\n";}
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