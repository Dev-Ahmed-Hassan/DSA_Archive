#include <vector>
#include <algorithm>
using namespace std;

// Make two arrays [0,1,2,3,4,5,6,7,8,9] these are indexes not values...
// then place the values in the respective index referring to the maximum digit...
// then add them.... 

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int max1[10] = {0}, max2[10] = {0};
        for (int num : nums) {
            int d = 0, t = num;
            while (t) {
                d = max(d, t % 10);
                t /= 10;
            }
            if (num > max1[d]) {
                max2[d] = max1[d];
                max1[d] = num;
            } 
            else if (num > max2[d]) max2[d] = num;
        }
        int res = -1;
        for (int i = 1; i < 10; ++i) {
            if (max2[i]) res = max(res, max1[i] + max2[i]);
        }
        return res;
    }
};



// kinda brute force approach but works!

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxSum = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (findMaxDigit(nums[i]) == findMaxDigit(nums[j])) {
                    int currentSum = nums[i] + nums[j];
                    if (currentSum > maxSum) {
                        maxSum = currentSum;
                    }
                }
            }
        }
        return maxSum;
    }

    int findMaxDigit(int x) {
        int maxDigit = 0;
        while (x > 0) {
            int digit = x % 10;
            if (digit > maxDigit) {
                maxDigit = digit;
            }
            x /= 10;
        }
        return maxDigit;
    }
};