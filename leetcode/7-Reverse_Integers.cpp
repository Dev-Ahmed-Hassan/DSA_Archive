#include <string>
#include <limits.h>
#include <stdexcept>
using namespace std;

// Approach: Digit extraction with 32-bit overflow checks
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x) {
            int digit = x % 10;
            if(ans > INT_MAX/10 || ans < INT_MIN/10) return 0;
            ans = ans * 10 + digit;
            x /= 10;
        }
        return ans;
    }
};
// Approach: Convert to string, reverse, handle overflow with try-catch
class Solution {
public:
    int reverse(int x) {
        string num = to_string(x);
        string rev = "";
        bool neg = false;
        int i = 0;
        
        if(num[0] == '-') { neg = true; i++; }

        for(; i<num.size(); i++) rev = num[i] + rev;

        try { return neg ? -stoi(rev) : stoi(rev); }
        catch(out_of_range& e) { return 0; }
    }
};
