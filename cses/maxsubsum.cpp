#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define int long long 
int n,m;
const int INF = 1e18;

void solve(){
    
    cin >> n ;
    vector<int> a(n);
    map<int,int> mp;
    int lo =INF,hi =0, avg =0;
    for (int i =0;i<n;i++){
        cin >> a[i];
        mp[a[i]]++;
        avg += a[i];
        lo = min(lo,a[i]);
        hi = max(hi,a[i]);
    }
    int ans =lo, sum = INF;
    while (lo <= hi){
        int mid = (lo+hi)/2;
        int mid_sum =0,slope =0;
        for (auto p :mp){
            if (p.f < mid){
                slope += p.s;
            }
            else {slope -= p.s;}
            mid_sum += abs(p.f-mid)*p.s;
        }
        if (slope > 0){
            hi = mid-1;
        }
        else {
            if (mid_sum <sum){
                ans = mid;
                sum =  mid_sum;
            }
            lo = mid+1;
        }
    }
    cout << sum <<endl;

    
    
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