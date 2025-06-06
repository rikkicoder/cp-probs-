// #include<bits/stdc++.h>
// #include <vector>
// #include <map>
// #include <string>
// #include <algorithm>
// #define int long long
// #define fo(n) for (int i=0;i<n;i++)
// using namespace std;

// void print (int i){
//     if (i) cout << "YES\n";
//     else cout << "NO\n";
// }

// int divi(int a,int b){
//     return (a % b == 0) ? ((a/b)) : ((a/b))+1;
// }
// int divo(int a, int b){return (a%b ==0) ? 0 :1;}

// int min (int a,int b){
//     return (a>b) ? b :a;
// }
// int max(int a, int b){
//     return (a>b) ?a: b;
// }
// int power2(int n){
//     return (n && !(n & (n-1)));
// }
// int32_t main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t;
//     cin >>t;
//     while (t--){
//         int n,k;
//         cin >> n >>k;
//         int a[n];
//         for(int i =0;i<n;i++){
//             cin >> a[i]; 
//         }
//     } 
//     return 0;
      
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Sort array in descending order
    sort(a.rbegin(), a.rend());

    // Sum of top k elements
    ll initial_sum = 0;
    for (int i = 0; i < k; i++) {
        initial_sum += a[i];
    }

    // Last painted element is either:
    // - The largest element not in top k (a[k]), if k < n
    // - Or one of the top k elements themselves
    ll last_painted = (k < n) ? a[k] : a[k - 1];

    // Total cost
    ll max_cost = initial_sum + last_painted;

    cout << max_cost << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
