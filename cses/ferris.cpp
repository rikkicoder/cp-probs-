#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,m;

void solve(){
    
    cin >> n >> m;
    vector<int> a(n),b(n);
    for (int i =0;i<n;i++){cin >> a[i];b[i] =a[i];}
    sort(b.begin(),b.end());
    vector<int> vis(n,0);
    int cnt  =0;
    int i =0,j=n-1;
    while (i <=j){
        //cout << i << " " << j << endl;
        if (i == j){cnt ++ ; break;}
        if (b[i]+b[j] <= m){
            cnt++;i++;--j;
        }
        else {
            cnt++;j--;
        }
    }
    cout << cnt <<endl;

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