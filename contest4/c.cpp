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
        vector<int> adjlist[n+1];
        int size[n+1];
        for(int i =0;i<n+1;i++){size[i] = 0;} 
        for (int i =0;i<n-1;i++){
            int a,b;
            cin >> a >> b;
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
            size[a]++;size[b]++;
        } 
        // for (int i=0 ;i <=n;i++){cout << size[i] << " ";}
        // cout <<endl;
        // for (int i =0;i<=n;i++){
        //     cout << i << ": ";
        //     for (int j : adjlist[i]){cout << j << " ";}
        //     cout << endl;
        // }
        int max1 =0,node1 =-1;
        for (int a =1;a<=n;a++){
            max1 = max(max1,size[a]);
            if(max1 == size[a]) node1 =a;
        }
        //cout << max1 <<" " << node1 <<endl;
        for (int h :adjlist[node1]){
            size[h]--;
        }
        int yes =0,max2 =0,node2 =-1;
        for  (int b =1;b<=n;b++){
            if(b!= node1){
                max2 = max(max2,size[b]);
                 if (size[b] == max2) node2 =b;
            }
        }
        //cout << node1 <<" " << node2<<endl;
        // for (int h : adjlist[node1]){
        //     if (h == node2) {yes =1;break;}
        // }
        if (n > 4){
            // if (yes) {
            //     int ans = size[node1]-1;
            //     ans += size[node2];
            //     cout << ans << endl;
            // }
            // else cout << size[node1]+size[node2]-1 <<endl;
            cout << size[node1]+size[node2] -1 <<endl;
        }
        else {cout << n-2 <<endl;}
        
        
        

    }
    return 0;
      
}
