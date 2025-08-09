#include <vector>
using namespace std;
// Approach: Two-pointer technique for O(n) time complexity
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0; int j = height.size()-1;
        int maxArea = 0;
        while(i<j)
        {
            int area = min(height[i], height[j]) * (j-i);
            if(area > maxArea) maxArea = area;
        if(height[i] < height[j])
        {
            i++;
        }
        else{
            j--;
        }
        }
        return maxArea;
    }
};