#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> A, pos;

// Return 1 if (v, v+1) forces a new round, else 0
int contributes(int v) {
    if (v < 1 || v+1 > n) return 0;
    return pos[v+1] < pos[v] ? 1 : 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    A.resize(n+1);
    pos.resize(n+1);

    for(int i = 1; i <= n; i++){
        cin >> A[i];
        pos[A[i]] = i;
    }

    // Initial rounds = 1 + # of v=2..n with pos[v]<pos[v-1]
    long long rounds = 1;
    for(int v = 2; v <= n; v++){
        if (pos[v] < pos[v-1]) 
            rounds++;
    }

    while(m--){
        int i, j;
        cin >> i >> j;
        int x = A[i], y = A[j];
        if (x == y) {
            cout << rounds << "\n";
            continue;
        }

        // We'll check these "value-pairs":
        int check[4] = { x-1, x, y-1, y };
        // Subtract their old contributions
        bool seen[4] = {0,0,0,0};
        for(int t = 0; t < 4; t++){
            int v = check[t];
            // avoid double-subtract if duplicates
            bool dup = false;
            for(int u = 0; u < t; u++){
                if(check[u] == v) { dup = true; break; }
            }
            if (!dup) rounds -= contributes(v);
        }

        // Swap the two elements in A[] and update pos[]
        A[i] = y;  A[j] = x;
        pos[x] = j; pos[y] = i;

        // Add back their new contributions
        for(int t = 0; t < 4; t++){
            int v = check[t];
            bool dup = false;
            for(int u = 0; u < t; u++){
                if(check[u] == v) { dup = true; break; }
            }
            if (!dup) rounds += contributes(v);
        }

        cout << rounds << "\n";
    }

    return 0;
}
