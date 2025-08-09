#include <iostream>
#include <vector>

using namespace std;


int satisfied(int target, vector<int> &arr, int mid)
{
    int totalWood =0 ;

    for(int x: arr)
    {
        if (x > mid)
        {
            totalWood += (x-mid);
        }
    }
    return totalWood >= target;
}


int findSawHeight(vector<int> &arr, int wood)
{
    int maxHeight = 0;
    for(int x: arr)
    {
        if (x > maxHeight)
        maxHeight = x;
    }

    int s=0, e=maxHeight, mid = s+(e-s)/2;
    int ans = -1;
    while(s<=e)
    {
        if(satisfied(wood, arr, mid))
        {
            ans = mid;
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main()
{
    vector<int> abc= {4,42,40,26,46};
    int target = 20;

    cout << findSawHeight(abc, target);
}