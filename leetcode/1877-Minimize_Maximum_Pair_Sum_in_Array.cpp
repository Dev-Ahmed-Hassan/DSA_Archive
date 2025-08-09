// one of the worst description a problem can ever have 
// basically it says that the sum should be minimized for each pair or something.. I don't even understand it now 

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        
        for(int i = 0; i < nums.size()/2; i++)
        {
            sum = max(nums[nums.size()-1-i]+nums[i], sum);
        }
        return sum;
    }
};