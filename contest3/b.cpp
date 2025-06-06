#include<bits/stdc++.h>
#include <vector>
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
int hcf(int a,int b){
    if (a < b){ int t =a; a =b; b = t;}
    while (a%b != 0){
        int g =a;int f = b;
        a = f;
        b = g%f;
    }
    return b;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >>t;
    while (t--){
        int n;
        cin >> n;
        vector<int> sides(n);
        for (int i=0;i<n;i++){ cin >> sides[i];}
        sort(sides.begin(),sides.end());
        int maxeside =0,i =0;
        while (i <n){
            int j = i+1;
            while (j < n){
                if (sides[i] == sides[j]) j++;
                else break;
            }
            if (j > i+1){maxeside = max(maxeside,sides[i]);}
            i =j;
        }
        int imp =0;
        vector <int> ans;
        // if (maxeside > 0){
        // ans.push_back(maxeside);
        // ans.push_back(maxeside);
        // }
        if (maxeside  >0){
            ans.push_back(maxeside);
            ans.push_back(maxeside);
            sides.erase(find(sides.begin(),sides.end(),maxeside));
            sides.erase(find(sides.begin(),sides.end(),maxeside));
            int k =0;
            while (k <sides.size()-1){
                if ((sides[k+1] -sides[k]) < 2*maxeside){ans.push_back(sides[k]);ans.push_back(sides[k+1]);break;}
                else k++;
            }
            if (ans.size() != 4) cout << -1 <<endl;
            else {for (int i=0;i<4;i++){cout << ans[i] << " ";}cout << endl;}

        }
        else cout << -1 <<endl;
        
        

       
    }
    return 0;
      
}






