#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;



// Most Optimized: sorting + 2 pointers
    // TC: O(n*log(n)) + O(n2), SC: O(1) for algorithm, rest for storing the solution.

    // IMP bcz Sorting helps to create unique triplets by not considering the duplicate elements for a variable: thus saving us space of saving triplets + checking if we've generated same triplet again.  
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();

    sort(nums.begin(), nums.end()); // so that we always only generate unique triplets by ignoring the duplicate elements && to not check if a triplet is previously generated.

    vector<vector<int>> triplets;

    for(int i = 0; i < n; ) {
        // fix i
        if(i > 0 && nums[i] == nums[i-1]) continue; // to get a new ith elem && we don't end up creating previously created triplets.

        int j = i+1, k = n-1;
        
        // explore all triplets with i(fixed)
        while(j < k) {

            int triplet_sum = nums[i] + nums[j] + nums[k];

            if(triplet_sum == 0) {
                // store the triplet and explore new triplets
                triplets.push_back({nums[i], nums[j], nums[k]}); // already in sorted order. 
                j++, k--;
                // inc j, dec k till both of them are different
                while(j < k && nums[j] == nums[j-1]) {
                    j++;
                }
                while(j < k && nums[k] == nums[k+1]) {
                    k--;
                }
            }
            else if(triplet_sum > 0) {
                // dec sum
                k--;
            }
            else {
                // inc sum
                j++;
            }
        }

    }
    return triplets;
}




// Better: hashing approach
    // TC: O(n2)*(log(n)), SC: O(n) + O(all triplets)
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    // Write your code here.

    set<vector<int>> st;
    
    set<int> hashset;

    // O(n2)*log(size of hashset)
    for(int i = 0; i < n; i++) {
        hashset.clear();

        for(int j = i+1; j < n; j++) {

            int third = -(arr[i] + arr[j]);
            // insert all the elements in between into a hashset
            if(hashset.find(third) != hashset.end()) {
                // present in set
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }

            hashset.insert(arr[j]);
        }
    }

    vector<vector<int>> ans(st.begin(), st.end()); // put all the vectors of st in ans
    return ans;
}





signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);



    return 0;
}