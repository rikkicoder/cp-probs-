#include <iostream>
#include <algorithm>
#include <vector>
typedef vector<int> vi;
typedef vector<pair<int,int>> vp;
using namespace std;


int main (){
    int t;
    cin >>t;
    while (t--){
        int n,m,L;
        cin >> n >> m >>L;
        vp hurdles;
        int x[m],v[m];
        for (int i=0;i<n;i++){
            int l,r;
            cin >>l >> r;
            hurdles.push_back({l,r});
        }
        for(int i=0;i<m;i++){cin >> x[i] >> v[i];}
        

    }
}
