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

int max (int a ,int b){
    return (a>b) ? a :b;
}



int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >>t;
    while(t--){
        int a,b,c,d;
        cin >>a >>b >>c>>d;
        int ans1 = a+b;
        int ans2 = c-b;
        int ans3 = d-c;
        int ans = 0;
        if (ans1 == ans2){
            if (ans2 ==  ans3){cout << 3 <<endl;}
            else {cout << 2 << endl;}
        }
        else{
            if (ans2  == ans3) {cout  <<2 <<endl;}
            else if (ans1  == ans3) cout << 2 <<endl;
            else cout <<  1<< endl;
        }
        
        

    }
    return 0;
      
}






