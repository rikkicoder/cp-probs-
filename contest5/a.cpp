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
        cin >> n;
        set <int> a,b;
        for (int i =0;i<n;i++){int h;cin >> h;a.insert(h);}
        for (int i =0;i<n;i++){int h;cin >> h; b.insert(h);}

        if(a.size() +b.size() <4) cout << "NO\n";
        else cout<< "YES\n";
        
        
        

    }
    return 0;
      
}
