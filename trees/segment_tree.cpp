#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
int arr[100100];

int t[400400];

void build(int index,int l ,int r){
    if (l == r){
        t[index] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    build(index*2,l,mid);
    build(2*index+1,mid+1,r);
    t[index] = t[2*index+1] + t[2*index]; //aggreagrate is addition
}

void update(int index, int l , int r, int pos, int val){
    if (pos < l || pos > r){return;}
    if (l==r){
        t[index]= val;
        //arr[l] = val;
        return;
    }
    int mid = (l + r) /2;
    update(2*index,l,mid,pos,val);
    update(2*index+1,mid+1,r,pos,val);
    t[index] = t[2*index]+t[2*index+1];
}

int query (int index, int l ,int r, int l_q, int r_q){
    if (l >  r_q  || r  < l_q){
        return 0;
    }
    if (l_q <= l && r <= r_q){
        // l_q <= l <= r_q <= r
        return t[index]; // return this because this will tho come 
    }
    int mid = (l+r)/2;
    return query(2*index,l,mid,l_q.r_q)+query(2*index+1,mid+1,r,l_q,r_q);

}

void solve(){
    int n;
    cin >> n;
    for (int i =0;i<n;i++){cin >> arr[i];}
    build(1,0,n-1);
    int q ;
    cin >> q;
    for(int i =0;i<q;i++){
        int ch; cin >> ch;
        if (ch == 1){
            int x,v;
            cin >> x >> v;
            update(1,0,n-1,x,v);

        }
        else {
            int l,r;
            cin >> l >> r;
            query(1,0,n-1,l,r);
        }
    }

}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int t;cin >> t;while(t--)
    solve();
}