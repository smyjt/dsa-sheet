// https://www.interviewbit.com/problems/repeat-and-missing-number-array/
// Given an array of containing N integers where each integer is in the range [1,N] inclusive appears once except for one missing and one repeating.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // Optimal solution: Using maths, solve the two equations based on sum and sum of squares
    // pair<int,int> findMissingAndRepeating(vector<int>& a, int n) {
    //     long long s=(n*(n+1))/2;
    //     long long p=(n*(n+1)*(2*n+1))/6;
    //     for(int i=0;i<n;i++) {
    //         s-=(long long)a[i];
    //         p-=(long long)a[i]*(long long)a[i];
    //     }
    //     pair<int,int> ans;
    //     ans.first=(p/s+s)/2;
    //     ans.second=(p/s-s)/2;
    //     return ans;
    // }

    // Optimal solution: Using XOR, separating into two buckets based on rightmost set bit
    pair<int,int> findMissingAndRepeating(vector<int>& a, int n) {
        int num=0;
        for(int i=0;i<n;i++) num^=a[i];
        for(int i=1;i<=n;i++) num^=i;
        int rsb=num&~(num-1),x=0,y=0;
        for(int i=0;i<n;i++) {
            if(a[i]&rsb) x^=a[i];
            else y^=a[i];
        }
        for(int i=1;i<=n;i++) {
            if(i&rsb) x^=i;
            else y^=i;
        }
        // Check which is missing and which is repeating before returning
        return {x,y};
    }
};

int main() {

    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    Solution obj; 
    auto ans=obj.findMissingAndRepeating(a,n);
    cout<<ans.first<<" "<<ans.second;

    return 0;
}

// Time complexity: O(N)
// Space complexity: O(1)