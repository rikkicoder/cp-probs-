#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;
const int INF = 1e9;

void solve(){
    int n,m; 
    cin >> n >> m;
    vi a(n);
    vector<string> z,nz;
    for (int &i : a){ 
        cin >> i;
        if (i%10 == 0) z.push_back(tostring(i));
        else nz.push_back(tostring(i));
    }
    int chars =0;
    for (auto s : nz){
        chars += s.size();
    }
    
    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
