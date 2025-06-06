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
        int n;
        cin >>n;
        vector<int>a(n);
        for (int i =0;i<n;i++){
            cin >>a[i];
        }
        sort(a.begin(),a.end());
        int mn= 0,flag =0;
        for (int i =0;i<n;i+=2){
            if (max(a[i],mn) != max(a[i+1],mn)){
                flag =1;
                break;
            }
            mn = max(a[i],mn)+1;
        }
        cout << (!flag ? "Yes\n":"No\n");      
    }
    return 0;
      
}


// if (n%2 != 1){
//     vector<int> a(n);
//     for (int i =0;i<n;i++){
//         cin >>a[i];
//     }
//     map<int,int> m;
//     int vis[n+1] ={0};
//     for (int i=0;i<n;i++){
//         m[a[i]]++;
//         vis[a[i]]++;
//     }
//     int flag =0;
//     // for (auto it = m.begin();it!= m.end();it++){
//     //     cout << it->first << ":" << it->second <<endl;
//     // }
//     for (auto it = m.begin();it != m.end();it++){
//         if ((vis[it->first] % 2) == 1){
//                 if (vis[it->first] == 1){
//                     flag =1;
//                     cout << "No\n";
//                     break;
//                 }
//             if (((vis[(it->first)-1] %2) ==1) && ((vis[(it->first)-1] ) >1)){
//                 vis[(it->first)-1]--;
//                 vis[it->first]++;
//             }
//             else if (((vis[(it->first)+1] %2) ==1) &&((vis[(it->first)] ) >1)){
//                 vis[(it->first)+1]++;
//                 vis[it->first]--;
//             }
//             else {
//                 flag =1;
//                 cout <<"No\n";
//                 break;
//             }
//         }
//     }
//     // for (auto it = m.begin();it!= m.end();it++){
//     //     cout << it->first << ":" << vis[it->first] <<endl;
//     // }
//     if (!flag) cout << "Yes\n";
//     }
//     else cout << "No\n";

