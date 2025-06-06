#include<bits/stdc++.h>
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
using namespace std;

vector<int> v= {1,2,3,4};
vector<int> w = move(v);


string str="Hello\tWorld\n";
string r_str = R"(Hello\tWorld\n)";
//we can use multiple lines in raw string
sort(v.begin(),v.end(),[](int a, int b){return a>b;});

//_builtin functions
__builtin_popcount(x) //counts the number of 1's in the binary representation of x
__builtin_clz(x) //counts the number of leading zeros in the binary representation of x
__builtin_ctz(x) //counts the number of trailing zeros in the binary representation of x
__builtin_parity(x) //counts the parity of x (even or odd number of 1's in binary representation)
__builtin_ffs(x) //returns the position of the first set bit in x (1-indexed)

//declare a vector in global if you cant use array because the size is large or unkown 
vector<vector<int>> dp;
//then when we got the sizes,
dp.resize(n+1, vector <int>(m+1,0)); // resize according to the given dimensions.

