#include <bits/stdc++.h> 
#include <vector>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> v;
    int i=0;
    for(i; i<mCols; i++)
    {
        if(i %2==0)
        {
            for(int j=0; j<nRows; j++)
            {
                v.push_back(arr[j][i]);
            }
        }
        else
        {
            for(int j=nRows-1; j>=0; j--)
            {
                v.push_back(arr[j][i]);
            }
        }
    }
        return v;

}