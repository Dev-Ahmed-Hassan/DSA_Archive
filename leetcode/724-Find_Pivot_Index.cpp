#include <vector>
using namespace std;


// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int total=0;
        int i=0;
        int j=0;
        int sum = 0;

        for(int x: nums)
        {
            sum+=x;
        }
        
        int  hsum = 0;

        for(int i = 0; i<nums.size(); i++)
        {
            if(i!= 0)
            {
                hsum+= nums[i-1];
            }
            if(hsum == (sum-nums[i])/2.0f)
            {
                return i;
            }
        }
        return -1;
    }
};