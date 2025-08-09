#include <iostream>
using namespace std;

int findpivot(int a[], int size);

int main()
{
    int arr[] = {6,7,9,1,2,3};  // not int arr = {9,7,1,2,3};

    cout << findpivot(arr, 6);
    return 0;
}

int findpivot(int a[], int size) // not int findpivot(int a{});
{
    int s=0,e = size-1, mid=s+(e-s)/2;
    int p=0;

    while(s<=e)
    {
        if(a[mid] > a[mid+1] || a[mid] < a[mid-1] )
        {
            return a[mid];
        }
        else if(a[0] > a[mid])
        {
            e=mid-1;
            mid = s+(e-s)/2;
        }
        else if(a[0]<a[mid])
        {
            s=mid+1;
            mid = s + (e-s)/2;
        }
    }
    return -1;
}