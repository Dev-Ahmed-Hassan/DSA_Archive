#include <vector>
using namespace std;
#include <limits.h>
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max = INT_MIN;
        int sum = 0;
        for(int x: gain)
        {
            sum+=x;
            if(sum>max) max = sum;
        }
        if(max >= 0)
        return max;
        else return 0;
    }
};