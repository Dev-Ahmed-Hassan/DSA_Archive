#include<iostream>
#include<vector>
#include<climits>
#include <cctype>
using namespace std;

// Approach: Check if a string is a valid palindrome
// You can also use isalnum() from <cctype> for cleaner code instead of a custom valid function.
class Solution {
public:
    static bool valid(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
    }

    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while (i < j) {
            if(valid(s[i]) && valid (s[j]))
            {
                if(tolower(s[i]) != tolower(s[j])) return false;
                i++;
                j--;
            }
            else if(valid(s[i]) && !valid (s[j])){
                j--;
            }
            else if(!valid(s[i]) && valid (s[j])){
                i++;
            }
            else
            {
                i++;
                j--;
            }
        }
        return true;        
    }
};

