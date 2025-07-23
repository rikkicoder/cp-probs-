#include<bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){
    int n;
    cin >> n;
    int arr[n];
    for (int i =0;i<n;i++){
        cin >> arr[i];
    }
    // Kadane's algorithm
    long long ans = -1e9;
    long long dp =0; // instead of maintaining O(n) space, we can only have a variable whihc only changes with i 
    for (int i =0;i<n;i++){
        dp = (i == 0 ? arr[i] : max(dp+arr[i],arr[i])); // dp[i] = ( i== 0 ? arr[i] : max(arr[i],dp[i-1]+arr[i]));
        ans = max(dp,ans);
    }
    int max_sum;
    cin >> max_sum; 
    //no of ways to get a sum if you can take 0-arr[i] from itj position;
    vector<vector<int>> dp(n+1,vector<int>(max_sum+1));
    vector<int> now_dp(max_sum+1), prev_dp(max_sum+1);
    for (int i =n-1;i>=0;--i){
        now_dp.assign(sum+1,0);
        for (int sum = 0;sum <= max_sum;sum++){
            if ( i == n-1){
                // dp[i][sum] = (sum == 0 ? 1 : 0);
                now_dp[sum]= (sum == 0 ? 1 : 0);
                continue;
            }
            // for (int x  = 0;x <= sum && x <= arr[i];x++) dp[i][sum] += dp[i+1][sum-x];
            // dp[i][sum] = dp[i+1][sum];
            now_dp[sum] = prev_dp[sum];
            if (sum - arr[i]-1 >= 0) now_dp[sum] -= prev_dp[sum-arr[i]-1]; // from total sum you either 

        }
        prev_dp = now_dp;
        // optimize further with prefix sum 
        // anyways we want sum of dp[i+1][sum] to dp[i+1][sum-arr[i]] so calculate prefix sum for whole row and compute the required sum.
        for (int sum  =1 ;sum <= max_sum;sum++){
            prev_dp[sum] += prev_dp[sum-1];
        }
    }
    // instead of dp[i+1] we can write prev_dp and dp[i] we can write next_dp so that we can also reduce space complexity even further

    // or also you can do dp[2][max_sum] and then dp[i][sum] -> dp[i&1][sum] and dp[i+1][sum] -> dp[(i+1)&1][sum] in the for loops
    // this will also do it off



    cout << prev_dp[max_sum]-prev_dp[max_sum-1] << endl;
    cout << ans << endl;
}

signed main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin >>t ;while (t--) 
    solve();
}