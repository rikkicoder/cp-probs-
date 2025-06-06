#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fo(n) for (int i=0;i<n;i++)


void print (int i){
    if (i) cout << "YES\n";
    else cout << "NO\n";
}

int divi(int a,int b){
    return (a % b == 0) ? ((a/b)) : ((a/b))+1;
}

void solve(){
    int n ;
    cin >> n;
    int a[n];
    for (int i = 0;i<n;i++){
        cin >> a[i];
    }
    vector <int> lis;

    for (int i =0;i <n;i++){
        if (lis.empty() || lis.back() <a[i]){
            lis.push_back(a[i]);
        }
        else {
            auto it = lower_bound(lis.begin(),lis.end(),a[i]); // find the first element which is greater than a[i]
            *it = a[i];
        }
    }

    cout << lis.size()<<endl;
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