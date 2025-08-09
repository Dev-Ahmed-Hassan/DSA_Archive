#include <vector>
using namespace std;

// Approach: Spiral order traversal of a matrix
// This might look messy but upon closer inspection, it is actually quite simple.
// The function iterates through the matrix in a spiral manner, collecting elements in a vector.
class Solution {
public:
    bool function(vector<vector<int>>& matrix, vector<int>& arr, int row,int col, int it) 
    {
        int count = col*row;
        int cR = 0, cC = 0;

        for (int j = it; j < col - it; j++) {
            arr.push_back(matrix[it][j]);
            cC = j;
        }
        if(arr.size() >= count) return false;
        
        for (int i = it+1; i < row - it; i++) {
            arr.push_back(matrix[i][cC]);
            cR = i;
        }

        if(arr.size() >= count) return false;
        
        for (int j = cC-1; j >= it; j--) {
            arr.push_back(matrix[cR][j]);
            cC = j;
        }
        
        if(arr.size() >= count) return false;

        for (int i = cR-1; i > it; i--) {
            arr.push_back(matrix[i][cC]);
        }

        if(arr.size() >= count) return false;

        return true;
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) { 
        vector<int> result; 
        int it=0;
        int row = matrix.size();
        int col = matrix[0].size();
        while (function(matrix, result, row, col, it))
        {
            it++;
        }
        return result;
    }
};