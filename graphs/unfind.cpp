#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second   

struct UnionFind{
    int n,set_size,*par,*rank;
    UnionFind(){}
    UnionFind(int a){
        n = set_size =a;
        par = new int[n+1];
        rank = new int[n+1];
        for (int i = 1; i <= n; i++){
            par[i] = i;
            rank[i] = 1;
        }
    }
    int find (int x){
        if (x != par[x]) return par[x] = find(par[x]);
        return x;
    }
    void merge (int x, int y){
        int xr = find(x);
        int yr = find(y);
        if (xr != yr){
            if (rank[xr] <= rank[yr]){
                rank[yr] += rank[xr];
                par[xr] =yr;
            }
            else{
                rank[xr] += rank[yr];
                par[yr] = xr;
            }
            set_size--;
        }
        
    }
    void reset(){
        set_size =n;for(int i =1;i<=n;i++){par[i] =i;rank[i] =1;}
    }
    int same(int x , int y){return (find(x) == find(y));}
    int size(){return set_size;}
    void print (){
        for (int i =1;i <=n;i++ ) cout << i << "->" << par[i] <<endl;
    }
};

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m,q;
    cin >> n >> m ;
    UnionFind uf(n);
    vector<pair<int,pair<int,int>>> edge;
    for (int i =0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        edge.push_back({c,{a,b}});

    }
    sort(edge.begin(),edge.end());
    int e =0,cost =0;   
    for (auto ed :edge){
        if (uf.find(ed.s.f) != uf.find(ed.s.s)){
            uf.merge(ed.s.f,ed.s.s);
            cost += ed.f;
            e ++;
        }
    }
    if (e!= n-1) cout << "IMPOSSIBLE\n";
    else {cout << cost <<endl;}
return 0;
}
