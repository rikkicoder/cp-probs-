#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin >> n;
    int a[n];
    for (int i =0;i<n;i++){
        cin >> a[i];

    }
    int ans  =0, temp =0;
    map<int,int> mp;
    for (int i =0;i<n;i++){
        if (mp[a[i]] == 0){
            mp[a[i]] = i+1;
            temp++;
        }
        else {
            cout << temp << '\n';
            ans = max(ans,temp);
            temp -= (mp[a[i]]-1);
            mp[a[i]] =i +1;
        }
    }
    cout  << max(ans,temp) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
