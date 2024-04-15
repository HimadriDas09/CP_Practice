#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n,k;
string str;

void solve() {
    if(k == n-1) {
        // i.e 1 char rem is always palindrome
        cout << "YES" << endl;
        return;
    }

    // for k == 0, just check the odd cnt total: which we'd have usually done after operations: so same approach

    vector<int> freq(26);

    // freq
    for(int i = 0; i < n; i++) {
        freq[str[i]-'a']++;
    }

    int cnt_to_remove = k;

    // in one iteration: reduce all the odd cnt by 1

    for(int i = 0; i < 26 && cnt_to_remove > 0; i++) {
        if(freq[i] & 1) {
            freq[i]--;
            cnt_to_remove--;
        }
    }
    // control(here): all odd cnts made even (by dec by 1) && cnt_to_remove is >= 0(now reduce even cnt by 2 each) OR cnt_to_remove became 0 and we couldn't convert some odd to even(which we cannot do now).

    // in one iteration: reduce all even cnts by 2 or 1
    for(int i = 0; i < 26 && cnt_to_remove > 0; i++) {
        
        if(!(freq[i] & 1) && freq[i] != 0 && cnt_to_remove >= 2) {
            freq[i] -= 2;
            cnt_to_remove -= 2;
        }
        else if((freq[i] & 1)) {
            freq[i]--;
            cnt_to_remove--;
        }
    }

    // here: cnt_to_remove will always be 0 

    // now check how many elem with odd cnt are there in string
    int odd_cnt = 0;
    for(int i = 0; i < 26; i++) {
        if(freq[i] & 1) odd_cnt++;
    }

    if(odd_cnt <= 1) cout << "YES" << endl;
    else cout << "NO" << endl;

}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        cin >> str;

        solve();
    }

    return 0;
}