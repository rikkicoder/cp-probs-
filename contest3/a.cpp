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
        vector<int> even,odd;
        for(int i=0;i<n;i++){
            int s;
            cin >>s;
            if (s%2==0) even.push_back(s);
            else odd.push_back(s);
        }
        int ev =even.size(),od =odd.size();
        int ans =0;
        if (ev > 0){
            ans = 1+od;
        }
        else ans = od-1;
        cout << ans << endl;
        
        

       
    }
    return 0;
      
}






