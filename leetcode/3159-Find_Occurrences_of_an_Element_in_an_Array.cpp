
#include<vector>    
using namespace std;

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> occurances = findOccurrences(x, nums);
        
        vector<int> result;
        for(int query: queries)
        {
            if(query > occurances.size())
            {
                result.push_back(-1);
            }
            else 
            {
                result.push_back(occurances[query-1]);
            }
        }
        return result;
        
    }
    vector<int> findOccurrences(int target, vector<int>& nums) {
    vector<int> occurrences;
    
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            occurrences.push_back(i);
        }
    }
    return occurrences;
}
    
};

