#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool isPossible(vector<int>& arr, int m, int mid) {
    int stud = 1, pages = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > mid) return false; 
        pages += arr[i];
        if (pages > mid) {
            pages = arr[i];
            stud++;
        }
        if (stud > m) return false;
    }
    return true; 
}

int findPages(vector<int>& arr, int n, int m) {
    if(m > n) return -1;
    int max=INT_MIN,sum=0; 
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
        sum += arr[i];
    }

    int s=max,e=sum,mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e)
    {
        if(isPossible(arr, m, mid))
        {
            ans = mid;
            e = mid-1;
        }
        else
        {
            s = mid +1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}