// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1/
// Find the count of all pairs such that a[i]>a[j] and i<j 

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int merge(vector<int>& a, vector<int>& temp, int low, int mid, int high) {
        int inv=0,i=low,j=mid+1,k=low;
        while(i<=mid && j<=high) {
            if(a[i]<=a[j]) temp[k++]=a[i++];
            else {
                temp[k++]=a[j++];
                // All elements in right of a[i] also make inversions
                inv+=mid+1-i;
            }
        }
        while(i<=mid) temp[k++]=a[i++];
        while(j<=high) temp[k++]=a[j++];
        // Copy back the merged elements to original array
        for(int i=low;i<=high;i++) a[i]=temp[i];
        return inv;
    }

    int mergeSort(vector<int>& a, vector<int>& temp, int low, int high) {
        int mid,inv=0;
        if(high>low) {
            mid=(low+high)/2;
            inv+=mergeSort(a,temp,low,mid);
            inv+=mergeSort(a,temp,mid+1,high);
            inv+=merge(a,temp,low,mid,high);
        }
        return inv;
    }
};

int main() {

    int n; cin>>n;
    vector<int> a(n),temp(n);
    for(int i=0;i<n;i++) cin>>a[i];
    Solution obj; 
    int ans=obj.mergeSort(a,temp,0,n-1);
    cout<<ans;

    return 0;
}

// Time complexity: O(NlogN)
// Space complexity: O(N)