#include <vector>
using namespace std;
#include <string>
class Solution {
public:
    bool check(string allowed, char chr)
    {
        for(char y: allowed){
            if(chr == y) return true;
        }
        return false;
    }
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        for (string x : words) {
            bool allow = true;
            for(char g: x)
            {
                if(!check(allowed, g)) allow = false;
            }
            if(allow) count++;
        }
        return count;
    }
};