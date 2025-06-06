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
int hcf(int a,int b){
    if (a < b){ int t =a; a =b; b = t;}
    while (a%b != 0){
        int g =a;int f = b;
        a = f;
        b = g%f;
    }
    return b;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >>t;
    while (t--){
        int n;
        cin >> n;
        int a[n];
        
        for(int i=0;i<n;i++){cin >> a[i];}
        int i =0;
        int flag =0;
        while (i < n-1){
            if (a[i] > a[i+1]){flag =1;break;}
            else {
                int g =a[i];
                a[i] = 0;a[i+1] -=g;
            }
            i++;
        }

        print(!flag);

       
    }
    return 0;
      
}






