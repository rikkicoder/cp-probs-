#include<bits/stdc++.h>
#include <vector>
#include <map>
#include <algorithm>
#define int long long
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

int max(int a,int b){
    return (a>b) ? a :b;
}

int MOD = 1e9 +7;

int n;
vector <int> a(301);
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >>n;
    for (int i=0;i<n;i++){cin >> a[i];}
    

return 0;
      
}






