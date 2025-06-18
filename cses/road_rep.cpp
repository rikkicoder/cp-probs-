#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define f first
#define s second
using pi = pair<int,int>;

struct UnionFind{
    int n, set_size,*par,*rank;
    UnionFind(){}
    UnionFind(int a){
        n = set_size =a;
        par  = new int[n+1];
        rank = new int[n+1];
        for (int i =1;i<=n;i++){
            par[i] = i;
            rank [i] =1;
        }
    }
    int find (int x){
        if (x != par[x]) return par[x]= find(par[x]);
        else return x;
    }
    void merge (int x , int y){
        int xr = find(x);
        int yr = find(y);
        if (xr != yr){
            if (rank[xr] >= rank[yr]){
                rank[xr] += rank[yr];
                par[yr] = xr;
            }
            else {
                rank[yr] += rank[xr];
                par[xr] = yr;
            }
            set_size--;
        }
    }
    int size() {return set_size;}

};

void solve(){
    int n,m;
    cin >>n >>m;
    int max_rank = 1;
    UnionFind uf(n);
    for (int i =0;i<m;i++){
        int a,b;
        cin >> a >> b;
        if(uf.find(a) !=  uf.find(b)){
            uf.merge(a,b);
            max_rank= max({max_rank,uf.rank[uf.find(a)]});
        }
        cout << uf.size() << " " << max_rank<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}