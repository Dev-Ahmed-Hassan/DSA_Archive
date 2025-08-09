#include<iostream>
#include<vector>
#include<climits>

using namespace std;



void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break; // Already sorted!
    }
}


int main()
{
    vector<int> arr= {1,5,6,7,3,5, 9,100,1000,12,32};
    
    bubbleSort(arr);

    for(int x: arr)
    {
        cout << x << endl;
    }
}