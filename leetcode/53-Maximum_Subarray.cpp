#include <vector>
#include <limits.h>
using namespace std;

// Approach: Kadane's algorithm for maximum subarray sum
// This algorithm runs in O(n) time complexity and uses O(1) space.
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentMax=INT_MIN;int sum=0;
        for(int x: nums)
        {
            if(sum+x < 0)
            {
                sum = 0;
                currentMax = max(currentMax, x);
            }
            else
            {
                sum += x;
                currentMax = max(currentMax, sum); 
            }
        }
        return currentMax;
    }
};