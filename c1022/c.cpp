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
        cin >>n;
        vector<int> a(n+2,0),b(n);
        for (int i=1;i<=n;i++){cin >>a[i];}
        int clones =0;
        int i =1;
        while (i<=n){
            int L =i;
            int v =a[i],R= i;
            while (R+1 <=n && a[R+1] == v){
                R++;
            }
            bool lh =(L>1 && a[L-1] >v);
            bool rh = (R<n && a[R+1] >v);
            if (!lh && !rh){
                clones++;
            }
            i = R+1;
        }
        cout << clones <<endl;
        
    } 
    return 0;
      
}


