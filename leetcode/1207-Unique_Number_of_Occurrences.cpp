#include <vector>
#include <algorithm>
using namespace std;

// There is a better solution with hash-maps.

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        if (arr.empty()) return true;

        sort(arr.begin(), arr.end());

        // Initialize temp to track seen frequencies
        vector<int> temp(arr.size() + 1, 0); // +1 to avoid out-of-bounds

        int currentCount = 1; // Start at 1 (first element is already counted)
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1]) {
                currentCount++;
            } else {
                // Check if this frequency was seen before
                if (temp[currentCount] != 0) {
                    return false;
                }
                temp[currentCount] = 1; // Mark frequency as seen
                currentCount = 1; // Reset for next element
            }
        }
        // Check the last group's frequency
        if (temp[currentCount] != 0) {
            return false;
        }
        return true;
    }
};
