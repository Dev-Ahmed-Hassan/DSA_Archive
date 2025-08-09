#include <vector>
#include <algorithm>
#include<cmath>
using namespace std;

// Finds by marking the visited elements in the array
// This approach runs in O(n) time complexity and uses O(1) space complexity.
class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) {
        std::vector<int> duplicates;

        for (int i = 0; i < nums.size(); ++i) {
            int index = std::abs(nums[i]) - 1; // Map value to 0-based index
            if (nums[index] < 0) {
                duplicates.push_back(index + 1); // Found a duplicate
            } else {
                nums[index] = -nums[index]; // Mark as seen
            }
        }

        return duplicates;
    }
};


// Kind of Brute force approach: Sort and find duplicates
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;

        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i] == nums[i+1])
            {
                temp.emplace_back(nums[i]);
                i++;
            }
        }
        return temp;
    }
};