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
        int n,l,r;
        cin >> n >> l >> r;
        int v1[n],v2[n];
        for(int  i=0;i<n;i++){cin >> v1[i];v2[i] = v1[i];}
        int sum1 =0,sum2=0;
        sort(v1,v1+r);
        sort(v2+l,v2+n);
        for (int i =0;i<=r-l;i++){sum1 += v1[i];}
        for (int i =l;i<=r;i++){sum2 += v2[i];}

        cout << min(sum1,sum2) << endl;
        

    }
    return 0;
      
}
