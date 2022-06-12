// https://leetcode.com/problems/next-permutation/
// Given an array of integers, find the next permutation. If such arrangement is not possible, then rearrange as the lowest.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // Optimal solution: Notice the pattern in every permutation has an increasing sequence of atleast one element from backwards.
    void nextPermutation(vector<int>& a) {
        
        int n=a.size(),i,j;
        // Find i such that a[i]<a[i+1]
        for(i=n-2;i>=0;i--) if(a[i]<a[i+1]) break;
        // Edge case: If it is the greatest possible permutation and hence no such i found
        if(i<0) {
            reverse(a.begin(),a.end());
            return;
        }
        // Find j such that a[j]>a[i]
        for(j=n-1;j>=0;j--) if(a[j]>a[i]) break;
        swap(a[i],a[j]);
        reverse(a.begin()+i+1,a.end());
    }
};

int main() {

    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    Solution obj; 
    obj.nextPermutation(a);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";

    return 0;
}

// Time complexity : O(N)
// Space complexity : O(1)