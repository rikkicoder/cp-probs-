//problem 2146 C

#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;
const int mod = 1e9+7;

#define noo  cout<<"NO\n";
#define yess  cout  << "YES\n";
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int i =0;i<n;i++){
        if (i > 0 && i< n-1){
            if (s[i-1] == '1' && s[i] == '0' && s[i+1] == '1'){
                noo
                return;
            }
        }
        if(s[0] == '0' && s[1] == '1'){
            noo
            return;
        }
        if (s[n-1] == '0' && s[n-2] == '1'){
            noo
            return;
        }
    }
    yess
    int i =0;
    while (i < n){
        if (s[i] == '1'){
            cout << i + 1 << " ";
            i++;
            continue;
        }
        int j = i;
        while (j < n){
            if (s[j] == '0') j++;
            else break;
        }
        cout << j << " ";
        for (int k = i;k<j-1;k++){cout << k+1 << " ";}
        i = j;
    }
    cout << '\n';


}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin >> t;while (t--)
    solve();
    return 0;
}