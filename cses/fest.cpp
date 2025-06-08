#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define int long long 
int n,m;

void solve(){
    
    cin >> n;
    priority_queue<pair<int,int>>times;
    for (int i =0;i<n;i++){
        int a,b;
        cin >> a>>b;
        times.push({-b,-a});
    }
    int t = 0,ans =0;
    while (!times.empty()){
        auto p = times.top();
        times.pop();
        if (-p.s >= t){
            //cout << p.f << " " << p.s << endl;
            ans++;
            t =-p.f;
        }

    }
    cout << ans  <<endl;
}

signed main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--){
        solve();
    }
}