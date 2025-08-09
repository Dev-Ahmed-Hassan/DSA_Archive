#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// Approach: Merge two sorted arrays in-place
// This approach runs in O(m+n) time complexity and uses O(1) space.
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j=0;
        for(int i=m;i<m+n;i++){
            nums1[i]=nums2[j++];
        }
        sort(nums1.begin(),nums1.end());
    }
};