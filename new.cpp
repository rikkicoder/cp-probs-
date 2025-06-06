#include <bits/stdc++.h>
using namespace std;
long long int divi(long long int a, long long int b){
    return (a%b == 0) ? a/b : (a/b)+1;
    
}

int main() {
    int t;
    cin >>t;
    while(t--){
        long long int x,n,m;
        cin >> x >> n >>m;
        long long int i =1;
        long long int x1=x,n1=n,m1=m;
        while (x1 > 0){
            if (n1 == 0 && m1 == 0) break;
            if (x1%2 == 0){
                x1 /= 2;
                if (n1 > 0) n1--;
                else m1--;
            }
            else {
                if (m1 > 0) {x1 = divi(x1,2);m1--;}
                else {x1/=2; n1--;}
            } 
        }
        long long int x2=x,n2=n,m2=m;
        while (x2 > 0){
            if((n2 ==0 && m2== 0)) break;
            if (x2%2 == 1){
                x2 /= 2;
                if (n2 > 0) n2--;
                else m2--;
            }
            else {
                if (m2 > 0) {x2 = divi(x2,2);m2--;}
                else {x2/=2; n2--;}
            } 
        }
        cout << x2 <<" " <<  x1 <<endl;
        
    }

    return 0;
}
