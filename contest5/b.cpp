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

    int n,k;
    cin >> n >> k;
    int aa[n];
    for(int i=0;i<n;i++){cin >>aa[i];}
    if(n!=k)
    {
        int nn=n-k+1, fa=0;
        for(int i=1; i<=nn; i++)
        {
            if(aa[i]!=1) fa=1; 
        }
        if(fa==0) {cout << 2 << endl; }
        else {cout << 1 <<endl;}
    }
    else
    {
        int temp=1;
        for(int i=1; i<n; i+=2)
        {
            if(aa[i]!=temp) {break;}
            temp++;
        }
        cout << temp << '\n';
    }

    }
    return 0;
      
}


