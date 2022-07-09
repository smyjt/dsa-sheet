// https://leetcode.com/problems/find-the-duplicate-number/
// Given an array of containing N+1 integers where each integer is in the range [1,N] inclusive, find the only repeated number.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // Optimal solution: Linked list cycle method
    int findDuplicate(vector<int>& a) {
        int slow=a[0],fast=a[0];
        // Find the collsion point
        do {
            slow=a[slow];
            fast=a[a[fast]];
        } while(slow!=fast);
        // Duplicate element forms a cycle whose distance from collision point and the start is equal
        fast=a[0];
        while(slow!=fast) {
            slow=a[slow];
            fast=a[fast];
        }
        // Point of cycle formation
        return slow;
    }
};

int main() {

    int n; cin>>n;
    vector<int> a(n+1);
    for(int i=0;i<=n;i++) cin>>a[i];
    Solution obj; 
    int ans=obj.findDuplicate(a);
    cout<<ans;

    return 0;
}

// Time complexity: O(N)
// Space complexity: O(1)