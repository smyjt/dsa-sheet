// https://leetcode.com/problems/merge-intervals/
// Merge all overlapping intervals, and return an array of the non overlapping intervals that cover all the intervals in the input.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<pair<int,int>> merge(vector<pair<int,int>>& intervals) {
        vector<pair<int,int>> ans;
        // Sort the intervals based on start index
        sort(intervals.begin(),intervals.end());

        int start=intervals[0].first,end=intervals[0].second;
        for(auto it:intervals) {
            if(it.first<=end) { // Overlapping detected, update end index of interval
                end=max(end,it.second);
            } 
            else { // No overlapping, insert the new interval
                ans.push_back({start,end});
                start=it.first;
                end=it.second;
            }
        }
        ans.push_back({start,end}); // Insert the last interval
        return ans;
    }
};

int main() {

    int n; cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++) 
        cin>>a[i].first>>a[i].second;
    Solution obj; 
    vector<pair<int,int>> ans=obj.merge(a);
    for(int i=0;i<ans.size();i++) 
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";

    return 0;
}

// Time complexity: O(NlogN)
// Space complexity: O(1)