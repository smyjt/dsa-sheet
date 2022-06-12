// https://leetcode.com/problems/maximum-subarray/
// Find the contiguous subarray having the largest sum and return its sum and print the subarray.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // Brute force: Take two for loops to generate the subarrays and keep a track of sum.
    // Optimal solution: Kadane's algorithm
    int maxSubarray(vector<int>& a, vector<int>& subarr) {
        int n=a.size(),sum=0,ans=INT_MIN,start=0;
        for(int i=0;i<n;i++) {
            sum+=a[i];
            if(sum>ans) {
                ans=sum;
                subarr[0]=start;
                subarr[1]=i;
            }
            if(sum<0) {
                sum=0;   
                start=i+1;
            }     
        }
        return ans;
    }
};

int main() {

    int n; cin>>n;
    vector<int> a(n), subarr(2);
    for(int i=0;i<n;i++) cin>>a[i];
    Solution obj; 
    int sum=obj.maxSubarray(a,subarr);
    cout<<sum<<"\n";
    for(int i=subarr[0];i<=subarr[1];i++) cout<<a[i]<<" ";

    return 0;
}

// Time complexity: O(N)
// Space complexity: O(1)