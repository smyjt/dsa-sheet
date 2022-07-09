// https://leetcode.com/problems/rotate-image/
// Given a matrix representing an image, rotate the image by 90 degrees clockwise.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // If matrix is m*n then we need to create another matrix of n*m and simulate in brute force
    // Optimal solution: If matrix is n*n
    void rotate(vector<vector<int>>& image) {
        int n=image.size();
        // Transpose the matrix
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                swap(image[i][j],image[j][i]);
            }
        }
        // Reverse every row
        for(int i=0;i<n;i++) {
            for(int j=0,k=n-1;j<k;j++,k--) {
                swap(image[i][j],image[i][k]);
            }
        }
    }
    // If anticlockwise, then take transpose followed by reversal of every column instead of row
};

int main() {

    int n; cin>>n;
    vector<vector<int>> a(n,vector<int>(n));
    for(int i=0;i<n;i++) 
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    Solution obj; 
    obj.rotate(a);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }

    return 0;
}

// Time complexity: O(N^2)
// Space complexity: O(1)