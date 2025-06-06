#include <iostream>
#include <algorithm>

#define sq(x) (x) * (x)

inline int sq1(int x){return x*x;}
using namespace std;

int main (){
    int a= 3;
    int c = sq1(++a);
    cout << c <<endl;

    return 0;

}