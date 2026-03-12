#include<bits/stdc++.h>
#define int long long
#define fo(n) for (int i=0;i<n;i++)
using namespace std;

void print (int i){
    if (i) cout << "YES\n";
    else cout << "NO\n";
}

int divi(int a,int b){
    return (a % b == 0) ? ((a/b)) : ((a/b))+1;
}

int min (int a,int b){
    return (a>b) ? b :a;
}
int max(int a, int b){
    return (a>b) ?a: b;
}

void solve(){
    int n,x,y;
    cin >>n >>x >> y;
    vi a(n);
    for(int &i :a) cin>>i;
    vi middles, corners;
    int i =0;
    int minmid =1e10,maxmid =0;
    while (i < n){
        if (i < x || i > y){
            corners.push_back(a[i]);
            
        }
        else {
            middles.push_back(a[i]);
            minmid = min(minmid,a[i]);
            maxmid = max(maxmid,a[i]); 
        }
        i++;
    }

    int stm =-1;
    for (int j =0; j<middles.size();j++){
        if (middles[j]==minmid) {stm = j;break;}
    }

    vi cacheleft,ans;
    int j = 0;
    while (j <  x && a[j] < minmid){
        ans.push_back(a[j]);
        j++;
    }
    while (j < x){
        cacheleft.push_back(a[j]);
        j++;
    }

    for (int k =stm;k != stm-1;k = (k+1)%middles.size()){
        ans.push_back()
    }
    
   
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}