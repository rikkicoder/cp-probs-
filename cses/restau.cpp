#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,m;

void solve(){
    
    cin >> n ;
    vector<int> ar(n),de(n);
    for (int i =0;i<n;i++){cin >> ar[i] >> de[i];}
    sort(ar.begin(),ar.end());
    sort(de.begin(),de.end());
    int ans  =0;
    int ma =0;
    int i =0,j=0;
    while(i <n || j <n){
        if (i == n){
            ans --;
            j++;
            continue;
        }
        if (j == n){
            ans++;
            ma =max(ma,ans);
            i++;
            continue;
        }
        if (ar[i] <= de [j]){
            ans ++;
            ma =max(ma,ans);
            i++;
        }
        else {
            ans --;
            j++;
        }
    }
    cout << ma<<'\n';

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