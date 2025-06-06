#include<bits/stdc++.h>
#include <vector>
#include <map>
#include <algorithm>
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

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >>t;
    while (t--){
        int n,m;
        cin >> n >>m;
        int a[n],b[m];
        int suma =0,sumb =0;
        fo(n){cin >> a[i];suma += a[i];}
        fo(m){cin >> b[i];sumb += b[i];}
        if (suma == sumb){
            int vis[n]; fo(n){vis[i] = 0;}
            


        }
        else cout << "NO\n";  
    }
    return 0;
      
}






