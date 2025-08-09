#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=0;
        for(int i=0; i<flowerbed.size(); i++)
        {
            bool prev = false, next = false;
            if(i> 0)
            {
                if(flowerbed[i-1] == 1) {prev = true;}
            }
            if(i< flowerbed.size()-1)
            {
                if(flowerbed[i+1] == 1){next = true;}
            }

            if(!prev && !next && flowerbed[i] == 0)
            {
                count++;
                flowerbed[i] = 1;
            }
        }
        if(count >= n) return true;
        else {return false;}
    }
};