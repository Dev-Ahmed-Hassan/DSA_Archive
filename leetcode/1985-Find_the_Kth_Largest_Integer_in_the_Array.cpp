#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Custom Comparator is the best choice here O(nlogn) Time Complexity

class Solution {
public:
    static bool check(const string &a, const string &b) {
    if (a.length() != b.length())
        return a.length() > b.length(); // Longer strings are "greater"
    
    return a > b; // Lexicographical comparison if lengths equal
    }
    
    string kthLargestNumber(vector<string>& nums, int k) {
       
        sort(nums.begin(), nums.end(), check);
        return nums[k-1];
    }
};



// This thing below works just fine but isn't efficient as it has O(n^2) time complexity.
class Solution {
public:
    bool check(string a, string b)
    {
        if(a.length() != b.length())
        return false;
        for(int i = 0; i<a.length(); i++)
        {
            if(a[i]-'0' < b[i]-'0')
            {
                return true;
            }
            else if(a[i]-'0' > b[i]-'0')
            {
                return false;
            }
        }
        return false;
    }
    
    string kthLargestNumber(vector<string>& nums, int k) {
       
        int i =0, j=0;
        while(i<nums.size() && j<nums.size())
        {
            if(nums[i].length() < nums[j].length() || check(nums[i], nums[j]))
            {
                string temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
            j++;
            if(j == nums.size())
            {
                j=i+1;
                i++;
            }
        }
        return nums[k-1];
    }
};