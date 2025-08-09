#include <vector>
#include <limits.h>
using namespace std;

// This approach runs in O(n) time complexity and uses O(1) space.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_buy = INT_MAX;
        int profit = 0;

        for(int x: prices)
        {
            if(x < min_buy)
            {
                min_buy = x;
            }
            if(x - min_buy > profit)
            {
                profit = x - min_buy;
            }
        }
        return profit;
        
    }
};