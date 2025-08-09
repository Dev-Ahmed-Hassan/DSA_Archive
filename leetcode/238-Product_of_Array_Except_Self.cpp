#include <vector>
using namespace std;
// Approach: Product of array except self using prefix and suffix products without DIVISION operation.
// This approach runs in O(n) time complexity and uses O(n) space complexity.


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1);  // Stores prefix products
        vector<int> suffix(n, 1);  // Stores suffix products
        vector<int> result(n, 1);  // Final result

        // Compute prefix products
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        // Compute suffix products
        for (int i = n - 2; i >= 0; --i) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        // Combine prefix and suffix
        for (int i = 0; i < n; ++i) {
            result[i] = prefix[i] * suffix[i];
        }

        return result;
    }
};