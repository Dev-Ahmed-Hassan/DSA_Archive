#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int prev = INT_MIN;
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i+1] < nums[i])
            {
                count++;
            }
        }
        return (count == 1 && nums[nums.size()-1] <= nums[0] || count == 0);
    }
};