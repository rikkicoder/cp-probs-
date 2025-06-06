// #include<bits/stdc++.h>
// #include <map>
// #include <string>
// #define int long long
// #define fo(n) for (int i=0;i<n;i++)
// #define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
// using namespace std;

// void print (int i){
//     if (i) cout << "YES\n";
//     else cout << "NO\n";
// }

// int divi(int a,int b){
//     return (a % b == 0) ? ((a/b)) : ((a/b))+1;
// }

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
//         int n;
//         cin >>n ;
//         vector<int>a(n);
//         for (int &i :a){cin >> i;}

        

        
        
        
//     } 
//     return 0;
      
// }

// 1006 c qn

// int n,x;
// cin >> n >>x;
// vector <int> a;
// int i = 1,ones =0,min =x+1;
// while (i <= x){
//     if (!(x&i)){
//         ones++;
//     }
//     else {
//         if (min > x){
//             min = i;
//         }
//     }
//     i = i *2;
// }


// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// const int MAXN = 150005;

// vector<int> tree[MAXN];
// vector<int> result;
// vector<bool> has_apple, visited;

// // modified bfs to return depth and farthest node
// pair<int, int> bfs(int start, int n) {
//     vector<int> dist(n + 1, -1);
//     queue<int> q;
//     q.push(start);
//     dist[start] = 0;
//     int farthest = start;

//     while (!q.empty()) {
//         int u = q.front(); q.pop();
//         for (int v : tree[u]) {
//             if (dist[v] == -1 && has_apple[v]) {
//                 dist[v] = dist[u] + 1;
//                 q.push(v);
//                 if (dist[v] > dist[farthest]) {
//                     farthest = v;
//                 } else if (dist[v] == dist[farthest] && v > farthest) {
//                     farthest = v; // lexicographically better
//                 }
//             }
//         }
//     }
//     return {dist[farthest], farthest};
// }


// // DFS to find path from u to v
// bool find_path(int u, int target, vector<int> &path, int parent) {
//     path.push_back(u);
//     if (u == target) return true;
//     for (int v : tree[u]) {
//         if (v != parent && !visited[v] && has_apple[v]) {
//             if (find_path(v, target, path, u)) return true;
//         }
//     }
//     path.pop_back();
//     return false;
// }

// void process_component(int start, int n) {
//     auto bfs_from = [&](int s) -> pair<int, vector<int>> {
//         vector<int> dist(n + 1, -1);
//         queue<int> q;
//         q.push(s);
//         dist[s] = 0;
//         while (!q.empty()) {
//             int u = q.front(); q.pop();
//             for (int v : tree[u]) {
//                 if (dist[v] == -1 && has_apple[v]) {
//                     dist[v] = dist[u] + 1;
//                     q.push(v);
//                 }
//             }
//         }
//         return {s, dist};
//     };

//     // First BFS
//     auto [s1, dist1] = bfs_from(start);
//     int u = start;
//     for (int i = 1; i <= n; ++i) {
//         if (has_apple[i] && dist1[i] > dist1[u]) {
//             u = i;
//         }
//     }

//     // Second BFS from u
//     auto [s2, dist2] = bfs_from(u);
//     int max_dist = 0;
//     vector<pair<int, int>> candidates;
//     for (int i = 1; i <= n; ++i) {
//         if (has_apple[i] && dist2[i] > max_dist) {
//             max_dist = dist2[i];
//             candidates.clear();
//             candidates.emplace_back(min(u, i), max(u, i));
//         } else if (has_apple[i] && dist2[i] == max_dist) {
//             candidates.emplace_back(min(u, i), max(u, i));
//         }
//     }

//     // Pick lexicographically best (u,v)
//     sort(candidates.rbegin(), candidates.rend());
//     tie(u, std::ignore) = candidates[0];
//     int v = candidates[0].second;

//     // Build path from u to v
//     vector<int> path;
//     function<bool(int, int)> dfs = [&](int curr, int target) {
//         path.push_back(curr);
//         if (curr == target) return true;
//         for (int next : tree[curr]) {
//             if (has_apple[next] && !visited[next]) {
//                 if (dfs(next, target)) return true;
//             }
//         }
//         path.pop_back();
//         return false;
//     };

//     fill(visited.begin(), visited.end(), false);
//     dfs(u, v);

//     for (int node : path) {
//         visited[node] = true;
//         has_apple[node] = false;
//     }

//     result.push_back(path.size());
//     result.push_back(u);
//     result.push_back(v);
// }




// int32_t main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;

//     while (t--) {
//         int n;
//         cin >> n;

//         // Clear previous data
//         for (int i = 1; i <= n; i++) {
//             tree[i].clear();
//         }
//         result.clear();
//         has_apple.assign(n + 1, true);
//         visited.assign(n + 1, false);

//         // Build the tree
//         for (int i = 1; i < n; i++) {
//             int u, v;
//             cin >> u >> v;
//             tree[u].push_back(v);
//             tree[v].push_back(u);
//         }

//         // Repeat while there are apples left
//         for (int i = 1; i <= n; i++) {
//             if (!visited[i] && has_apple[i]) {
//                 process_component(i, n);
//             }
//         }

//         // Output the result
//         for (int val : result) {
//             cout << val << " ";
//         }
//         cout << '\n';
//     }

//     return 0;
// }
// Write your code here
// Write your code here

// ************** GOC code  ***************


// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int fact[201];
// const int mod = 1e9+7;


// void solve(){
//     int R,B,r,b;
//     cin >> R >> r >> B >> b;
//     int g = fact[R+B-r]/(fact[R-r-1]*fact[B]);
//     int x = fact[R+B-b]/(fact[R]*fact[B-b-1]);
//     int y = fact[R+B-r-b]/(fact[R-r-1]*fact[B-b-1]);
//     int n = fact[R+B]/(fact[R]*fact[B]);
//     int ans = (n-(g+x-y))%mod;
//     cout <<ans <<endl;



// } 


// signed main (){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     fact[0]=1;
//     fact[1] =1;
//     for (int i = 2; i <= 200; i++){
//         fact[i] = (fact[i-1]*i)%mod;
//     }
//     int t;
//     cin >> t;
//     while(t--){
//         solve();
//     }

// return 0;
// }

// #include<bits/stdc++.h>
// #define int long long
// using namespace std;
// using vi = vector<int>;

// void solve(){
//     int n,m;
//     cin >>n >> m ;
   

    
// }

// signed main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t;
//     cin >> t;
//     while (t--){
//         solve();
//     }

//     return 0;
// }


