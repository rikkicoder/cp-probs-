#include <bits/stdc++.h>
#define int long long
using namespace std;

using vi = vector<int>;

void solve(){
    int n;
    cin >> n;
    
    vector<array<int,3>> customers(n);
    for (int i = 0; i<n ;i++){
        cin >> customers[i][0] >> customers[i][1];
        customers[i][2] = i;
    }
    
    sort (customers.begin(),customers.end());
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vi ans(n,0);
    int curr_rno = 1,max = 0;
    for (auto c : customers){
        
        if (pq.empty()){
            pq.push({c[1],1});
            ans[c[2]] = 1;
            continue;
        }
        else if(pq.top().first < c[0]){
            int room = pq.top().second;
            pq.pop();
            pq.push({c[1],room});
            ans[c[2]] = room;
        }
        else {
            curr_rno++;
            pq.push({c[1],curr_rno});
            ans[c[2]] = curr_rno;
        }
    }
    
    cout << curr_rno << '\n';
    for (auto x : ans) cout << x << " ";
    cout << '\n';
    


        
}



signed main() {
	// your code goes here
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	int t=1;
	//cin >> t;
	while(t--){
	    solve();
	}

}
