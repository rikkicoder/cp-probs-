#include<bits/stdc++.h>
#include <vector>
#include <map>
#include <string>
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
        int n,m;
        cin >>n >> m;
        int a[n];
        int b;
        for (int i=0;i<n;i++){cin >> a[i];}
        cin >> b;
        int ab[n];
        for (int i=0;i<n;i++){
            ab[i] = b-a[i];
        }
        vector<int> ans;
        ans.push_back(min(a[0],ab[0]));
        int k =1;
        while (k < n-1){
        
        }

        
    }
    return 0;
      
}
