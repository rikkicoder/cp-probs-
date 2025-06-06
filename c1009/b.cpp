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
int power2(int n){
    return (n && !(n & (n-1)));
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >>t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a;
        for (int i =0;i<n;i++){
            int x;
            cin >> x;
            a.push_back(x);
        }
        sort(a.begin(),a.end());
        int sum  = a[0];
        int j = 1;
        while (j< n){
            sum +=(a[j]-1);
            j++;
        }
        cout << sum <<endl;
        
    } 
    return 0;
      
}



