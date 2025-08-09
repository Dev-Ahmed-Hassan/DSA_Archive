#include<iostream>
#include<vector>

using namespace std;



void insertionSort(vector<int> &arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        int key = arr[i];
        int j = i-1;
        
        while(j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    vector<int> arr= {1,5,6,7,3,5, 9,100,1000,12,32};
    
    insertionSort(arr);

    for(int x: arr)
    {
        cout << x << endl;
    }
}