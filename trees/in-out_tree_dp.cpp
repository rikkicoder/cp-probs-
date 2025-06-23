#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> tree[100001];
int indp[100011];
int outdp[100011];
int dp[100011][101];

int gcd(int a, int b){
    if (!a || !b) return a^b;
    else {
        if(a <b) swap(a,b);
        return gcd(b,a%b);
    }
}
void dfsin(int node, int par){
    parent[node] = par;
    indp[node] =0;
    for (auto chl : tree[node]){
        if (chl != parent[node]){
            dfsin(chl,node);
            indp[node] = max(indp[node],indp[chl]+1);
        }
    }
}

void dfsout(int node, int par,int outval){
    outdp[node] = outval; //outdp of curr node done.

    // now prepare for child's outdp

    int max1 = -1,max2 =-1;
    for (auto chld : tree[node]){
        if (chld != par){
            if (indp[chld] > max1){
                max2 = max1;
                max1 = indp[chld];    
            }
            else if (indp[chld] > max2){
                max2 = indp[chld];
            }
        }
    }// for every child we are taking the top two values,
    for (auto ch : tree[node]){
        if (ch != par){
            if (indp[ch] == max1){
                // and then for every child, the outval is already calculated and sent
                dfsout(ch,node,max(outdp[node]+1,max2+2));
            }else {
                dfsout(ch,node,max(outdp[node]+1,max1+2));
            }
        }
    }
}

int dp_dfs(int node,int parn, int path_gcd){
    if (dp[node][path_gcd] != -1) return dp[node][path_gcd];
    int ans = 0;
    for (int k = 1;k<=m;k++){
        int temp =1,chcnt =0;
        for (auto ch : tree[node]){
            if (ch != parn){
                chcnt++;
// for every colour possible for curr node, check the childs possibilities and multiply them.
                temp *= dp_dfs(ch,node,gcd(path_gcd,k)); 
            }
        }
        if (chcnt == 0) {if (gcd(path_gcd,k) == 1) ans++;}
        else{
            ans  += temp;
        }
    }

    return dp[node][path_gcd] = ans;
}
void solve(){
    cin >> n;
    for(int i =0;i<n-1;i++){
        int a,b;
        cin >> a>> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfsin(1,0);
    dfsout(1,0,0);
    int ans[n];
    for (int i =1;i<=n;i++){
        ans[i] = max(indp[i],outdp[i]);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //int t;cin >>t;while(t--)
    solve();
} 