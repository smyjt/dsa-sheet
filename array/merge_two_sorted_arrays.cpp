// https://leetcode.com/problems/merge-sorted-array/
// Merge two sorted arrays in place

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // Insertion sort method
    void merge(vector<int>& a, vector<int>& b, int m, int n) {
        int i,j;
        for(i=0;i<m;i++) {
            if(a[i]>b[0]) swap(a[i],b[0]);
            int first=b[0];
            for(j=1;j<n && b[j]<first;j++) {
                b[j-1]=b[j];
            }
            b[j-1]=first;
        }
    }

    // Optimal: Gap method in O((M+N)log(M+N)) time and O(1) extra space
    // void merge(vector<int>& a, vector<int>& b, int m, int n) {
    //     int gap=(m+n+1)/2;
    //     while(gap>1) {
    //         int i=0,j=gap;
    //         while(j<m+n) {
    //             if(j<m && a[i]>a[j]) swap(a[i],a[j]);
    //             else if(i<m && j>=m && a[i]>b[j-m]) swap(a[i],b[j-n]);
    //             else if(i>=m && j>=m && b[i-m]>b[j-m]) swap(b[i-m],b[j-n]);
    //             i++;
    //             j++;
    //         }
    //         gap=(gap+1)/2;
    //     }
    // }
};

int main() {

    int m,n; cin>>m>>n;
    vector<int> a(m),b(n);
    for(int i=0;i<m;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    Solution obj; 
    obj.merge(a,b,m,n);
    for(int i=0;i<m;i++) cout<<a[i]<<" ";
    for(int i=0;i<n;i++) cout<<b[i]<<" ";

    return 0;
}

// Time complexity: O(M*N)
// Space complexity: O(1)