#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;


string getBinary(int x) {
    bitset<8> b(x); // creates a bitset of size 8 && initialized with the binary rep of x

    return b.to_string();
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    // int -> by default has 32 bits
    // 6:   110
    // 12: 1100 
    // 6 & 12:  0100 -> 4


    // AND 

    // int a = 6, b = 12;
    // int c = a&b;

    // cout << getBinary(a) << endl;
    // cout << getBinary(b) << endl;
    // cout << getBinary(c) << endl;


    // OR 

    // int d = 12, e = 16;
    // int f = d|e;

    // cout << d << ":-"<< getBinary(d) << endl;
    // cout << e << ":-"<< getBinary(e) << endl;
    // cout << f << ":-"<< getBinary(f) << endl;


    // cout << getBinary(18) << endl;



    // XOR

    // int a = 25, b = 43;
    // int c = a^b;

    // cout << getBinary(a) << endl;
    // cout << getBinary(b) << endl;
    // cout << getBinary(c) << endl;


    // left shift
    int a = 36;
    int b = a << 2; // original num * 2 pow 2

    cout << getBinary(a) << endl;
    cout << getBinary(b) << endl;
    cout << b << endl;

    return 0;
}