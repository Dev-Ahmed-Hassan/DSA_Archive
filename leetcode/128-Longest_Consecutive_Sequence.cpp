#include <vector>
#include <algorithm>
using namespace std;

// Approach: Find the longest consecutive sequence in an unsorted array
// Optimal Solution uses a hash set to track elements and runs in O(n) time complexity with O(n) space complexity.
// But this one uses sorting, which runs in O(n log n) time complexity and O(1) space complexity.


class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        // a longest and a current variable for streaks
        int longest = 1;
        int current = 1;
        // for empty input vectors
        if(nums.size() == 0)
        {
            longest = 0;
            current = 0;
        }
        // size calculation
        int size = nums.size()-1;
        // sorting the input vector
        sort(nums.begin(), nums.end());
        // main for loop
        for(int i=0; i<size; i++)
        {
            // check if the next number in array is the current number + 1
            if(nums[i]+1 == nums[i+1])
            {
                current+=1;
            }
            // do nothing if the number is equal to the previous number
            else if (nums[i] == nums[i+1])
            {
                
            }
            // if the streak is broken
            else
            {
                // if the streak is longer than the previous
                if(current > longest)
                {
                    longest = current;
                }
                current = 1;
            }
        }
        //  if the streak is never broken (for 0,5,6,7) now the longest is never updated, so to cover that, here is the condition.
        if(current > longest)
        longest = current;
        // return the answer;
        return longest;
    }
};