#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

string binaryString(int x) {
    bitset<8> b(x);
    return b.to_string();
}


// check which bit is set and which is unset
// since total for integer: 32 bits

void checkSetBit(int num) {

    for(int b = 0; b < 32; b++) {
        if(num & (1 << b)) {
            // LOGIC: for 1: only 1 bit at 0th pos -> and we're left shifting that bit to the position of the bit we're checking in num and ANDING them both 
                // 1: bth bit is set
                // 0: bth bit is not set
            cout << "set bit" << endl;
        }
        else {
            cout << "bit not set" << endl;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    // while checking for set and unset bits:   
        // if ith bit is set: print out a number in which it's exactly num but only the ith bit is unset 
    
    int num = 16; 

    // For 1: we can left the 1 to any bit location using << or >>

    cout << binaryString(num) << endl;

    for(int b = 0; b < 32; b++) {
        if(num & (1 << b)) {
            // just unset the bth set bit: rest all same
            // eg: 1010101(1)10101 -> maintain everything else
                // (xoring/oring) rest part with 0: rest remains same
                // xoring bth bit with 1: unset

            int res = num ^ (1 << b);
            cout << "set to unset" << binaryString(res) << endl;
        }
        else {
            // just set the unset bit: rest all same
            // eg: 10101010(0)101010 
                // (xoring/oring) rest pair with 0: rest remains same
                // xoring 0th bit with 1: 1
                // oring 0th bit with 1: 1
                    // do any

            int res2 = num | (1 << b);
            cout << "unset to set" << binaryString(res2) << endl;
        }
    }

    return 0;
}