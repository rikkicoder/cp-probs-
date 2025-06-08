#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,m;

void solve(){
    
    cin >> n >> m;
    vector<int> a(n),b(m);
    for (int i =0;i<n;i++){cin >> a[i];}
    for (int i =0;i<m;i++){cin >> b[i];}
    multiset<int> s(a.begin(),a.end());
    vector<int> ans;
    for (int i =0;i<m ;i++){
        int x =b[i];
        auto it = s.upper_bound(x);

        if (it == s.begin()){ans.push_back(-1);}
        else {
            --it;
            ans.push_back(*it); 
            s.erase(it);
           
        }   
    }
    for(auto an  :ans){cout << an <<"\n";}

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