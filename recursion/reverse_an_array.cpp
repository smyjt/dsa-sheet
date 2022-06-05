// Reverse an array using recursion.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void reverse(vector<int>& a, int i, int j) {
        if(i>=j) return;
        swap(a[i],a[j]);
        reverse(a,i+1,j-1);
    }
};

int main() {

    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    Solution obj;
    obj.reverse(a,0,n-1);
    for(int i:a) cout<<i<<" ";

    return 0;
}

// Time complexity : O(n)
// Space complexity : O(1)