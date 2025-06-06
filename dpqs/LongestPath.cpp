#include<bits/stdc++.h>
#include <vector>
#include <map>
#include <algorithm>
#define int long long
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

int max(int a,int b){
    return (a>b) ? a :b;
}
int dist[100001];
int ans = 0;
int n,m;
vector <int> comp;
void dfs (vector<vector<int>> &graph,vector<bool> & visited,int s){
    visited[s] =true;
    //cout << "t" << endl;
    for (int i : graph[s]){
       if (!visited[i]) dfs(graph,visited,i);
    }
    comp.push_back(s);
}


void top_sort(vector<vector<int>> &graph,vector<bool> &visited){
    comp.clear();
    for(int i =0;i<n;i++){
        if(!visited[i]) dfs(graph,visited,i);
    }
    reverse(comp.begin(),comp.end());
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);  
        cin >> n >> m;
        vector<vector<int>> graph(n);
        for(int i =0;i< m;i++){
            int a,b;
            cin >> a >> b;
            graph[a-1].push_back(b-1);
        }
        vector<bool> visited(n,0);
        for (int i =0;i<n;i++){dist[i] = 0;}
        top_sort(graph,visited);
        for (int x:comp){
            for(int e :graph[x]){
                dist[e] = max(dist[e],dist[x]+1);
            }
        }
        // int ans =0;
        for (int i=0;i<n;i++){ans = max(ans,dist[i]);}
        cout << ans <<endl;
        //for (int x: comp){cout << x <<" ";}
       



    return 0;
      
}






