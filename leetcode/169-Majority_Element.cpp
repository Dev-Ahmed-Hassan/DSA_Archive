//Moore's Voting Algorithm

#include <vector>
using namespace std;    
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate = -1;
        for(int num : nums) {
            if(count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
};

// sorting approach
#include <vector>   
#include <algorithm>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int majority = nums.size()/2;
        int temp = nums[0];
        int frequency=0;
        for(int x: nums){
            if(x == temp)
            {
                frequency++;
            }
            else{
                temp = x;
                frequency = 1;
            }
            if(frequency > majority)
            {
                return temp;
            }
        }
        return -1;
    }
};