#include <bits/stdc++.h>
#define int long long
using namespace std;
using vi = vector<int>;
#define f first
#define s second

void solve(){
    int n,x;
    cin >> n >>x;
    vi a(n),b(n);
    for (int &i :a)cin >> i;
    b =a;
    sort(b.begin(),b.end());
    int i =0,j=n-1;
    pair<int,int> aw;
    while(i<j){
        //cout << i << " : " << b[i] << " " << j << endl;
        int sum =b[i]+b[j];
        if (sum > x){--j;}
        else if (sum < x){
            i++;
        }
        else{
            aw.f = b[i];
            aw.s = b[j];
            //cout << aw.f << " " << aw.s << '\n';
            break;
        }
    }
    if (i >= j){cout << "IMPOSSIBLE\n";}
    else {
        pair<int,int> ans;
        for(int i =0;i<n;i++){
            if (a[i] == aw.f){ans.f = i+1;break;}
        }
        for(int i =0;i<n;i++){
            if (a[i] == aw.s && i != ans.f-1){ans.s = i+1;break;}
        }
        cout << ans.f << " " << ans.s <<'\n'; 
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t =1;
    //cin >> t;
    while(t--){
        solve();
    }
}