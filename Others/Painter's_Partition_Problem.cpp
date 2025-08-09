#include<climits>
#include <vector>
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


int findLargestMinDistance(vector<int> &boards, int k)
{

    int sum=0, max = INT_MIN, min=INT_MAX;

    for(int i=0; i<boards.size(); i++)
    {
        sum+= boards[i];
        if(boards[i] > max)
        {
            max = boards[i];
        }
        if(boards[i] < min)
        {
            min = boards[i];
        }
    }

    if(k==1) return sum;

    int s=max, e=sum-min, mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e)
    {
        if(isPossible(boards, k, mid))
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