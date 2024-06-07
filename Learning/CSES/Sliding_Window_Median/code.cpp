#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n,k;
int arr[200000];

// class to define the data structure
class currentWindow {
public:
    multiset<int> left,right;
    int leftsize; // left set size should be (k+1)/2

    currentWindow(int x) {
        leftsize = x;
    }

    void balance() {
        // if left set has lesser elem than it should be, then smaller elem from right move to left, (if we can) till right has <= elem than left.

        while(left.size() < leftsize) {
            if(right.empty()) break; // bcz then nothing can be moved to left set

            left.insert(*right.begin());
            right.erase(right.begin()); // pass the iterator since passing the values deletes all occurrences from the multiset.
            
        }

        // sim, if right has lesser elem than it should be then move elem greater elem from left->right

        while(left.size() > leftsize) {
            if(left.empty()) break;

            right.insert(*left.rbegin());
            left.erase(left.find(*left.rbegin()));
        }
    }

    void insert(int x) {
        if(!left.empty() && x < *left.rbegin()) {
            left.insert(x);
        }
        else {
            right.insert(x);
        }

        balance();
    }

    void remove(int x) {
        // from where to erase
        auto it = right.find(x);
        if(it == right.end()) {
            // not found in right, so present in left
            left.erase(left.find(x)); // can't do left.erase(x) bcz then it deletes all references
        }
        else {
            right.erase(it);
        }

        balance();
    }

    int getMedian() {
        return *left.rbegin();
    }

};


void solve() {
    // create the data structure
    currentWindow cw((k+1)/2); // we pass the # elem that should be left_set

    // enter 1st 'k' elem
    for(int i = 0; i < k; i++) {
        cw.insert(arr[i]);
    }
    cout << cw.getMedian() << " ";

    // now slide over every window i.e insert and erase
    int st = 0;
    for(int end = k; end < n; end++, st++) {
        cw.insert(arr[end]);
        cw.remove(arr[st]);

        cout << cw.getMedian() << " ";
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];

    solve();

    return 0;
}