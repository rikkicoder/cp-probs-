#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
int main (){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >>n;
        vector<int> a(n);
        for (int i=0;i<n;i++){cin >> a[i];}
        set<int>sf,sb;
        int forw[n],back[n];
        for (int i=0;i<n;i++){
            sf.insert(a[i]);
            forw[i] = i+1-sf.size();
        }
        for (int j= n-1;j>=0;--j){
            sb.insert(a[j]);
            back[j] = (n-j)-sb.size();
        }
        int mark[n]={0};
        int i =0,j=0;
        while(i<n-1){
            if (forw[i]!=forw[i+1]) mark[i+1] =1;
            i++;
        }
        while (j<n-1){
            if (back[j]!=back[j+1]) mark[j] =1;
            j++;
        }
        int length[n]={0},mx=0,mi=0;
        if (mark[0] == 0) {length[0] =1;mx =1;mi =1;}
        for (int i =1;i<n;i++){
            if (mark[i] == 0) {
                length[i] = length[i-1]+1;
                if (mx < length[i]) {mx= length[i];mi= i+1;}
            }
        }
        if(mx == 0) {
            //if (n ==1) cout <<"1 1\n";
            cout << "0\n";
        }
        else {
            cout << mi-mx+1 << " " << mi <<endl;
        }
         
        
        
        
    }
    
}