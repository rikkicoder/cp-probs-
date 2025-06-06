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
        int x;
        cin >> x;
        string s;
        cin >> s;
        int ans  =0;
        int i= 0,c =0;char prev = s[0];
        while(i <x){
            if (s[i] != prev){
                ans++;
            }
            
            prev = s[i];
            i++;
        }
        if (s[0] == '1') ans++;
        cout << ans <<endl;
        
    }
        
    return 0;
      
}



