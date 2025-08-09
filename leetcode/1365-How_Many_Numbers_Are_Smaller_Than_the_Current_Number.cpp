#include <vector>
using namespace std;
#include <algorithm>
// Using Binary Search to find how many numbers are smaller than the current number
// Time Complexity: O(n log n)
class Solution {
public:
    int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int result = -1; 

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            right = mid - 1; 
        } else if (arr[mid] < target) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }

    return result; 
}
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> temp = nums;
        vector<int> result;
        sort(temp.begin(), temp.end());
        for(int x: nums)
        {
            int idx = binarySearch(temp, x);
            if (idx >= 0) result.push_back(idx); 
        }
        return result;
    }
};