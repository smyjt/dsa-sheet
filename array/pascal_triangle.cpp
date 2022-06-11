// https://leetcode.com/problems/pascals-triangle/
// Given an integer n, return the first n rows of Pascal's triangle.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> pascal(n);
        
        for(int i=0;i<n;i++) {
            // In zero based indexing, ith row will have i+1 values
            pascal[i].resize(i+1);
            // Edge case to consider: The first and last value of every row is 1
            pascal[i][0]=pascal[i][i]=1;
            for(int j=1;j<i;j++) 
                pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
        }
        
        return pascal;
    }
};

int main() {

    int n; cin>>n;
    Solution obj; 
    vector<vector<int>> pascal=obj.generate(n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<=i;j++)
            cout<<pascal[i][j]<<" ";
        cout<<"\n";
    }

    return 0;
}

// Time complexity : O(N^2)
// Space complexity : O(1)