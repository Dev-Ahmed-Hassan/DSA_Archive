#include <vector>
using namespace std;

// Approach: Find the single number in an array where every other number appears twice
// This approach uses the XOR operation, which runs in O(n) time complexity and uses O(1) space.


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int temp = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            temp = temp^nums[i];
        }
        return temp;
    }
};