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
        cin >>n;
        vector <int> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        int ans=0;
        // int i = -2;
        // while (i < n){
        //     int j  =0;
        //     int k =0;
        //     while (j <n){
        //         if (j == i) {j += 1; k = max(k,1);continue;}
        //         k = max(k,a[j+1]-a[j]);
        //         j += 2;
        //     }
        //     ans = min(k,ans);
        //     i += 2;
        // }
        int allowed = n%2;
        if (!allowed){
            for ( int i =0;i<n;i+=2){
                ans = max (a[i+1]=a[i],ans);
            }
        }
        else if (n == 1) ans = 1;
        else {
            int in =0,ma =0;
            for (int i =0;i<n-1;i++){
                ma = max(ma,a[i+1]-a[i]);
                if ( ma = a[i+1]-a[i]) in = i;
            }
            in = in %2;
            in = (in+1)%2;
            while ( in < n){
                ans = max(ans,a[in+1]-a[in]);
                in += 2;
            }
        }
        cout <<  ans << endl;

    }
    return 0;
      
}
