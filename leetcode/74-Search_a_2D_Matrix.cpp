#include <vector>
using namespace std;

// Approach: Search in a 2D matrix using binary search
// This approach treats the 2D matrix as a 1D array and performs binary search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int s = 0;
        int e = row*col-1;
        int m = s + (e-s)/2;
        while(s<=e)
        {
            int element = matrix[m/col][m%col];

            if(element == target)
            {
                return true;
            }
            if(element < target)
            {
                s = m+1;
            }
            else if(element > target)
            {
                e = m-1;
            }
            m = s + (e-s)/2;
        }
        return false;
    }
};