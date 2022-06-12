// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Return the maximum profit you can achieve by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int maxProfit(vector<int>& prices) {
        // Keep track of the minimum buying price
        int ans=0,buy=INT_MAX;
        for(int p:prices) {
            // Update buy, if current price is less than minimum buying price till now
            buy=min(buy,p);
            // Check if the selling price-minimum buying price is maximum or not
            ans=max(ans,p-buy);
        }
        return ans;
    }
};

int main() {

    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    Solution obj; 
    int profit=obj.maxProfit(a);
    cout<<profit<<"\n";

    return 0;
}

// Time complexity: O(N)
// Space complexity: O(1)