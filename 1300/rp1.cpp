#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;
const int mod = 1e9+7;


void solve(){
    int n;
    cin >> n;
    int i  = 0;
    while (n > 1){
        if (n % 2 == 0) {n = n/2;}
        else break;
    }
    // cout << "N = " << n << '\n';
    while(1){
        if((1 << i)  > n) break;
        i++;
    }
    --i;
    if (i == -1) {cout << ((n == 1) ? "NO\n" : "YES\n");return;}
    // cout << "i = " << i << '\n';
    for(int j = 0;j <= i -j;j++){
        int f = ((n >> j) & 1);
        int s = ((n >> i-j) & 1);
        if (j == i-j){
            if (f == 1){
                cout << "NO\n";
                return;
            } 
        }
        // cout << f << " " << s <<'\n';
        if (f != s) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";

}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin >> t;while (t--)
    solve();
    return 0;
}