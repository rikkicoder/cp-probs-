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



int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >>t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int cards [n][m];
        for(int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                cin >> cards[i][j];
            }
        }
        int start =0;
        int flagg =0;
        int rem[n];
        for(int i=0;i<n;i++){
            rem[i] = (cards[i][0]%n)+1;
            for (int j=0;j<m;j++){
                if (rem[i] != (cards[i][j]%n)+1) {flagg =1;break;}
            }
            if (flagg == 1){break;}
        }
        if (flagg == 1) cout <<-1<<endl;
        else{
            for (int i=1;i<=n;i++){
                for (int j=0;j<n;j++){
                    if (rem[j] == i)cout << j+1 << " ";
                }
            }
            cout<<endl;
        }

        }
        
        // int fllag =0;
        // while(start < n){
        //     int ind = -1;
        //     for(int i=0;i<n;i++){
        //         int flag  =0;
        //         for (int j=0;j<m;j++){
        //             if (cards[i][j] == start) {flag =1;break;}
        //         }
        //         if (flag == 1) {ind = i;break;}
        //     }
        //     //cout << fllag <<" " <<ind << endl;
        //     if (vis[ind] == -1){vis[ind] = start+1;}
        //     else {fllag =1;break;}
        //     start++;
        // }
        // while (start <n*m ){
        //     if (fllag) break;
        //     int got  = 0;
        //     for (int i =0;i<m;i++){
        //         if (cards[start%n][i] == start){got =1;break;}
        //     }
        //     if (got == 0) fllag =1;
        //     start++;
        // }
        // if (fllag = 0) {for(int i=0;i<n;i++){cout << vis[i] << " ";}cout <<endl;}
        // else cout <<-1<<endl;
    
    return 0;
      
}






