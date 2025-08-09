#include<iostream>
#include<vector>
#include<climits>

using namespace std;


void SelectionSort(vector<int> &arr){
	int min = 0;
	for(int i=0; i<arr.size()-1; i++){
		min = i;
		for(int j=i+1; j<arr.size(); j++){
			if(arr[j] < arr[min]){
				min = j;
			}
			

		}	
		if(i!=min){
			int temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}

	}

}



int main()
{
    vector<int> arr= {1,5,6,7,3,5, 9,100,1000,12,32};
    
    SelectionSort(arr);

    for(int x: arr)
    {
        cout << x << endl;
    }
}