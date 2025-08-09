#include <vector>
using namespace std;

// This approach starts from the top-right corner and moves left or down based on the comparison with the target.
// It runs in O(m + n) time complexity, where m is the number of rows   

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        int ridx = 0;
        int cidx = c-1;

        while(ridx < r && cidx >= 0)
        {
            int element = matrix[ridx][cidx];

            if(element == target)
            {
                return true;
            }
            else if(element > target)
            {
                cidx--;
            }
            else {
                ridx++;
            }
        }
        return false;
    }
};