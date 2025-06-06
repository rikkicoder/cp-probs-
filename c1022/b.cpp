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

int popcountll(int y){
    return __builtin_popcountll((unsigned long long) y);
}

int cost2(int y){
    if(y==0) return 2;
    if (y ==1) return 5;
    if ((y & (y-1))==0) return y+2;
    return y;
}
int cost3(int y){
    if (y==0) return 6;
    int pc = popcountll(y);
    if (pc <=2) return y+2;
    return y;
}

const int INF = (int)4e18;
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >>t;
    while (t--){
        int n,x;
        cin >>n>>x;
        if (n==1){
            cout<< (x>0 ?x:-1)<<endl;
            continue;
        }
        int ans =INF;
        int R = (min(n, (int)32));
        for (int r=1;r<=R;r++){
            if (r>n) break;
            int m =n-r;
            int par = m&1;
            int y = x^par;
            if (r==1){
                if (y>0) ans= min(ans,m+y);
            }
            else if (r==2){
                int c2 = cost2(y);
                ans = min(ans,m+c2);
            }
            else{
                if (popcountll(y)>=r) ans =min(ans,m+y);
            }
        }
        cout << (ans < INF/2 ? ans :-1)<<endl;

        
    } 
    return 0;
      
}


