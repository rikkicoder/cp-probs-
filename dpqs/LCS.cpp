#include<bits/stdc++.h>
#include <vector>
#include <stack>
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

int max(int a , int b){
    return (a>b) ? a :b;
}


//dp[3001][3001];



int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s,t;
    cin >> s;
    cin >> t;
    int dp[t.size()+1][s.size()+1];
    for (int i =0; i<=s.size();i++){dp[0][i] = 0;}
    for (int i =0;i <=t.size();i++){dp[i][0] = 0;}
    for (int i =1;i<=t.size();i++){
        for (int j = 1;j<=s.size();j++){
            if (s.at(j-1) == t.at(i-1)){dp[i][j] = 1+dp[i-1][j-1];}
            else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    }
    stack<char> ans;
    int i = t.size(),j = s.size();
    while (i >0 && j > 0){
        if (dp[i][j-1] == dp[i][j] || dp[i][j] == dp[i-1][j]){
            if (dp[i][j-1] == dp[i][j]) j--;
            else if (dp[i][j] == dp[i-1][j]) i--;
        }
        else if (dp[i][j] == 1+ dp[i-1][j-1]){ans.push(t.at(i-1));i--;j--;}
    }
    while (!ans.empty()){
        cout << ans .top();
        ans.pop();
    }
    cout<<endl;    
return 0;
}






