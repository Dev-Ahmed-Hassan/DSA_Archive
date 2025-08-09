#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    // Approach: Rotate the array in-place using reverse using built-in functions
    // This approach runs in O(n) time complexity and uses O(1) space.

    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) return;
        k = k % nums.size();  // Handle cases where k > nums.size()
        if (k == 0) return; 
        std::rotate(nums.begin(), nums.end() - k, nums.end());
    }


    // Alternative approach: Rotate the array using three reversals
    // This approach also runs in O(n) time complexity and uses O(1) space
    
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) return;
        k = k % nums.size();
        if (k == 0) return;
        
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};