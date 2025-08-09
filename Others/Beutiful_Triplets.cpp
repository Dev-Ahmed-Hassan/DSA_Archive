#include <iostream>
#include<vector>

using namespace std;

// this is the approach using the binary search 
bool find(int x, vector<int> arr)
{
    int s=0; int e = arr.size(); int mid = s + (e-s)/2;

    while(s<=e)
    {
        if(arr[mid] == x)
        {
            return true;
        }
        else if (arr[mid] > x)
        {
            e = mid-1;
        }
        else if(arr[mid] < x)
        {
            s = mid+1;
        }
        mid = s + (e-s)/2;
    }
    return false;
}

int beautifulTriplets(int d, vector<int> arr)
{
    int count = 0;

    for(int x: arr)
    {
        if(find(x+d, arr) && find(x+(2*d), arr))
        {
            count++;
        }
    }
    return count;
}



// This is the brute force approach 
int beautifulTriplets(int d, vector<int> arr) {
    
    int count = 0;
    
    for(int i=0; i<arr.size()-2; i++)
    {
        bool second = false, third = false;
        int center = 0;
        
        for(int j=i+1; j<arr.size(); j++)
        {
            
            if(!second && abs(arr[i] - arr[j]) == d)
            {
                second = true;
                center = arr[j];
            }
            else if(!third && second && abs(center - arr[j]) == d)
            {
                count++;
                break;
            }
        }
    }
    return count;
}

