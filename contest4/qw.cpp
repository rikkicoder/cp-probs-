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
int max(int a, int b){
    return (a>b) ?a: b;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >>t;
    while (t--){
        int n;
        int mi= 1e9+1,in =-1;
        cin >>n;
        vector <int> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
            mi =min(mi,a[i]);
            if (mi == a[i]) in =i;
            //cout << mi << " " << in <<endl;
        }
        int flag =0;
        for (int i=0;i<n;i++){
            if (abs(a[i]-mi) < abs(i-in)){flag =1; break;}
            if (mi < 2*(i-in))
        }
        if (mi < 2) flag =1;
        if (flag) cout << "NO\n";
        else cout << "YES\n";

    }
    return 0;
      
}
