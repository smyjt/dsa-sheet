// https://leetcode.com/problems/sort-colors/
// Given an array with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // Optimal solution: Dutch National Flag algorithm
    void sortColors(vector<int>& a) {
        int low=0,mid=0,high=a.size()-1;
        while(mid<=high) {
            if(a[mid]==0) {
                swap(a[low++],a[mid++]);
            }
            else if(a[mid]==1) {
                mid++;
            }
            else if(a[mid]==2) {
                swap(a[mid],a[high--]);
            }
        }
    }
};

int main() {

    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    Solution obj; 
    obj.sortColors(a);
    for(int i:a) cout<<i<<" ";

    return 0;
}

// Time complexity: O(N)
// Space complexity: O(1)