// #include <bits/stdc++.h>
// #define int long long
// using namespace std;
// using vi = vector<int>;
// using pi = pair<int,int>;
// #define f first
// #define s second
// const int INF = 4e18;

// int arr[200100];

// int t[800400];

// void build (int index, int l , int r){
//     if (l == r){
//         t[index] = arr[l];
//         return;
//     }
//     int mid =  (l+r)/2;
//     build(2*index,l,mid);
//     build(2*index+1,mid+1,r);
//     t[index] = t[2*index]^t[2*index+1];
// }

// int query (int index, int l , int r, int lq, int rq){
//     if (l > rq|| r < lq) return 0;
//     if (lq <=l && r <= rq){
//         return t[index];
//     }
//     int mid = (l+r)/2;
//     return query(2*index,l,mid,lq,rq)^query(2*index+1,mid+1,r,lq,rq);
    
// }

// void solve(){
//     int n,q;
//     cin >> n >>q;
//     for (int i =0;i< n;i++){cin >> arr[i];}
//     build(1,0,n-1);
//     while (q--){
//         int l,r;
//         cin >> l >> r;
//         cout << query(1,0,n-1,l-1,r-1) << '\n';
//     }
    
    
// }
// signed main (){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;
//     // cin >> t;
//     while(t--){
//         solve();
//     }
//     return 0;
// }


#include <bits/stdc++.h>
#define int long long
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
#define f first
#define s second
const int INF = 4e18;

int arr[200100];

int t[800400];

void build (int index, int l , int r){
    if (l == r){
        t[index] = arr[l];
        return;
    }
    int mid =  (l+r)/2;
    build(2*index,l,mid);
    build(2*index+1,mid+1,r);
    t[index] = t[2*index]+t[2*index+1];
}


void query (int index, int l , int r, int lq, int rq, int val){
    if (l > rq|| r < lq) return;
    if (l == r){
        t[index] += val;
        return;
    }
    int mid = (l+r)/2;
    query(2*index,l,mid,lq,rq,val);
    query(2*index+1,mid+1,r,lq,rq,val);
    t[index] = t[2*index]+t[2*index+1];
}

void solve(){
    int n,q;
    cin >> n >>q;
    for (int i =0;i< n;i++){cin >> arr[i];}
    build(1,0,n-1);
    while (q--){
        int type;
        cin >> type;
        if (type  == 1){
            int l,r,u;
            cin >> l >> r >> u;
            query(1,0,n-1,l-1,r-1,u);
        }
        else{
            int k;
            cin >> k;
            cout << arr[k-1] << '\n';
            
        }
    }
    
    
}
signed main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}