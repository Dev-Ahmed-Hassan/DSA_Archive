#include<vector>
using namespace std;

#include <bits/stdc++.h> 
int findSecondLargest(int n, vector<int> &arr)
{
    if (arr.empty()) {return -1;}
    int Largest = arr[0], secondLargest=INT_MIN;

    for(int x: arr)
    {
        if(x > Largest)
        {
            secondLargest = Largest;
            Largest = x;
        }
        else if(x!= Largest && x > secondLargest )
        {
            secondLargest = x;
        }
    }
    if(secondLargest == INT_MIN)
    {return -1;}
    return secondLargest;
}