#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi =vector<int>;
using pi = pair<int,int>;
const int INF = 4e18;

int n,k;
vi tree[200010];
int val[200010];
int dp[200][2][200];
int dp2[200010][50];
int sbz[202];
void dfs(int node, int par){
    // intialize like it is a leaf.
    for(int i=0;i<200;i++){
        dp[node][0][i] = (i == 0 ? 0 :-INF); // IF I DONT TAKE THEN THERE SHOULDNT BE ANY NEED TO 
        dp[node][1][i] = (i == 1 ? val[node] : -INF); // IF I TAKE THEN I GOT TO ADD THE VAL
    }
    for(auto ch : tree[node]){
        dfs(ch,node);
        // EVERYTHING RELATED TO THE CHILD IS CALCULATED.
        sbz[node] += sbz[ch];
        for (int a = k; a>=0;--a){
            for (int b =k;b >=0;--b){
                dp[node][0][a+b] = max(dp[node][0][a+b] , dp[node][0][a]+max(dp[ch][0][b],dp[ch][1][b]));
                // WE ARE TAKING THE OPRIMAL VALUE FOR EACH CHILD
                //LOOPING BACKWARDS BECAUSE THE DP IS CUMULATIVE
                dp[node][1][a+b] = max(dp[node][1][a+b],dp[ch][0][b]+dp[node][1][a]);   
            }
        }
    }
}
 
void solve(){
    cin >> n >> k;
    fot(int i =0;i<=n;i++){
        tree[i].clear();
        val[i] =0;
    }
    for(int i =0 ;i<n-1;i++){
        int a,b;
        cin >>a  >>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1,0);
    cout << max(dp[1][0][k],dp[1][1][k]) << '\n';

    
}


signed main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >>t; while(t--) solve();
    return 0;
}
