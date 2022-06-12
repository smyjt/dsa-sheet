// https://leetcode.com/problems/set-matrix-zeroes/
// Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // Optimized solution: Replace dummy arrays with first row and column.
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m=matrix.size(),n=matrix[0].size();
        // Variable to consider zeroes of first column, as matrix[0][0] is overlapping
        bool col0=true;
        
        for(int i=0;i<m;i++) {
            if(matrix[i][0]==0) col0=false;
            for(int j=1;j<n;j++) {
                if(matrix[i][j]==0) matrix[i][0]=matrix[0][j]=0;
            }
        }
        
        // Traverse in reverse order so that changes in the first row and column is made at the very end
        for(int i=m-1;i>=0;i--) {
            for(int j=n-1;j>0;j--) {
                if(matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j]=0;
            }
            // Check for first column at last
            if(!col0) matrix[i][0]=0;
        }
    }
};

int main() {

    int m,n; cin>>m>>n;
    vector<vector<int>> a(m,vector<int>(n));
    for(int i=0;i<m;i++) 
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    Solution obj; 
    obj.setZeroes(a);
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }

    return 0;
}

// Time complexity: O(M*N)
// Space complexity: O(1)