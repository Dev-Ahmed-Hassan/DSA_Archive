// We use the fact that this list is ordered until the peak and then ordered in reverse after it.
// We find mid.. Check if its the peak... if not then we check if its before or after the peak.
// Then we update the start/end and mid;

#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

     int start = 0;
     int end = arr.size()-1;
     int mid = start + (end - start)/2;
     int max = 0;
     int idx = 0;

     while(start <= end)
     {
        
            max = arr[mid]; 
            idx = mid;
            if(arr[mid + 1] < arr[mid] && arr[mid-1] < arr[mid])
            {
                return idx;
            }
            else if(arr[mid+1] > arr[mid])
            {
                start = mid+1;
                mid = start + (end-start)/2;
            }
            else if(arr[mid+1] < arr[mid])
            {
                end = mid-1;
                mid = start + (end-start)/2;
            }
    }
    return idx;
    }
};