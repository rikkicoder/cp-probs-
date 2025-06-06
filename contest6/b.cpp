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
        string s;
        cin >>s;
        int i =0,flag =0;
        int z=0;
        while (i < s.size()-1){
            if (s.at(i) == s.at(i+1)){
                flag =1 ; z= i;
            }
            i++;
        }
        if (!flag) cout << s.size()<<endl;
        else cout <<1 << endl;
        
    }
    return 0;
      
}
