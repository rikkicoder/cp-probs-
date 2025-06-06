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

long long int divi(long long int a,long long int b){
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
       cin >>n >> m;
       int ans =4*m;
       vector<pair<int,int>> coods;
       for (int i= 0;i<n;i++){
            int x,y;
            cin >>x >>y;
            coods.push_back({x,y});
       }
       for(int i=1;i<n;i++){
        ans += (2*(coods[i].first + coods[i].second));
       }
       cout << ans <<endl;
    }
    
}




