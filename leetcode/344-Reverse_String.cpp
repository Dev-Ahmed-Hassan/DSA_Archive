#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:

    // use this for competitive programming
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }

    // use this for interview 
    void reverseArray(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }

    
}
};