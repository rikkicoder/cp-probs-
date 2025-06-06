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

int MOD = 1e9 +7;
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int h,w;
    cin >> h >>w;
    vector<vector<char>>a(h,vector<char>(w));
    int dp[h+1][w+1];
    for (int i =0;i<h;i++){
        for (int j=0;j<w;j++){cin >> a[i][j];}
    }

    for (int i =0;i<=h;i++){
        for (int j =0;j<=w;j++){
            dp[i][j] =0;
        }
    }
    dp[0][1] =1;
    for (int i =1;i<=h;i++){
        for(int j =1;j<=w;j++){
            if (a[i-1].at(j-1) == '.'){
                dp[i][j] = (dp[i-1][j]+dp[i][j-1])%MOD;
            }
        }
    }

    cout << dp[h][w] <<endl;

    
    


    return 0;
      
}






