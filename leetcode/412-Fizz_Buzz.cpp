#include <vector>
using namespace std;    
#include <string>
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for(int i=0; i<n; i++)
        {
            string word = to_string(i+1);

            if((i+1)%3==0 && (i+1)%5==0) word = "FizzBuzz";
            else if((i+1)%3==0) word = "Fizz";
            else if((i+1)%5==0) word = "Buzz";

            result.push_back(word);
        }
        return result;
    }
};