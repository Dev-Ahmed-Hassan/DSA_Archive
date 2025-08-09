#include <vector>
using namespace std;

// Approach: Find pivot and perform binary search

class Solution {
public:
    
    int findpivot(vector<int> a) {
        int s=0, e=a.size()-1;
        while(s<e) {
            int mid = s+(e-s)/2;
            if(mid < e && a[mid] > a[mid+1]) {
                return mid;
            }
            if(mid > s && a[mid] < a[mid-1]) {
                return mid-1;
            }
            if(a[s] >= a[mid]) {
                e = mid-1;
            } else {
                s = mid+1;
            }
        }
        return -1; // no rotation
}

    int search(vector<int>& nums, int target) {
        int p = findpivot(nums);
        if(p == -1) { // array not rotated
            // normal binary search
            int s=0, e=nums.size()-1;
            while(s <= e) {
                int m = s+(e-s)/2;
                if(nums[m] == target) return m;
                if(nums[m] < target) s = m+1;
                else e = m-1;
            }
            return -1;
        }
        
        // decide which part to search
        if(target >= nums[0]) {
            // search in left part
            int s=0, e=p;
            while(s <= e) {
                int m = s+(e-s)/2;
                if(nums[m] == target) return m;
                if(nums[m] < target) s = m+1;
                else e = m-1;
            }
        } else {
            // search in right part
            int s=p+1, e=nums.size()-1;
            while(s <= e) {
                int m = s+(e-s)/2;
                if(nums[m] == target) return m;
                if(nums[m] < target) s = m+1;
                else e = m-1;
            }
        }
        return -1;
    }
};





