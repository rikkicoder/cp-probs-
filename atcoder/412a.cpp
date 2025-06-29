#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n; cin >> n;
    int a[n];
    for (int i =0 ;i<n;i++)  cin >> a[i];
    sort(a+1,a+n-1);
    //for (auto j : a)cout << j << " ";
    //cout << '\n';
    int l =1, r=n-1,ans =2;
    if (a[l-1]*2 >= a[r]){cout << 2 << endl; return;}
    if (n == 2) {cout << -1 << '\n'; return ;}
    while(l < r){
        auto m = (upper_bound(a+l-1,a+r,2*a[l-1])-a);
        //cout << m << ' ' << l << ' ' << r << '\n';
        if (m == l) {cout << -1 << '\n'; return;}
        if (2*a[m-1] >= a[n-1]){cout << ans+1 <<'\n'; return;}
        ans++;
        l = m;
    }
    cout << ans <<'\n';
}

signed main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;cin >>t;while(t--)
    solve();
return 0;
}



