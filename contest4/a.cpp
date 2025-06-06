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
        int l,r;
        cin >> l >> r;
        if (l==1 && r== 1)cout <<1 << endl;
        else cout << r-l <<endl;

       
    }
    return 0;
      
}
