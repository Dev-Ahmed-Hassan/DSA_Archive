#include <vector>
#include <algorithm>
using namespace std;

// Sort and return the duplicate number in an array
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i] == nums[i+1])
            {
                return nums[i];
            }
        }
        return 0;
    }
};