#include<bits/stdc++.h>
#include <vector>
#include <map>
#include <algorithm>
//#define int long long
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
int hcf(int a,int b){
    if (a < b){ int t =a; a =b; b = t;}
    while (a%b != 0){
        int g =a;int f = b;
        a = f;
        b = g%f;
    }
    return b;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >>t;
    while (t--){
        int n,k;
        cin >> n >> k;
        int a[n];
        vector <int> vis(n,0);
        for(int i=0;i<n;i++){cin >> a[i];vis[a[i]-1] ++;}
        int i =0,ans =0;
        int maxm = k/2 -1;
        while(i <= min(k-2,n-1)){
            if (k-2-i < n){
            if (i != k-2-i )ans += min(vis[i],vis[k-2-i]);
            else ans += ((vis[i]/2)*2);
            }
            i++;
        }
        cout << ans/2<<endl;

        

       
    }
    return 0;
      
}






