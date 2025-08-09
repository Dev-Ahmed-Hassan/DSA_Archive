#include<iostream>
#include<vector>
#include<climits>

// Approach: Reverse the words in a string
// This approach splits the string by spaces, reverses the words, and then joins them back

using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        string tempWord = "";
        string tempString = "";
        bool first = true;
        
        for(char x : s) {
            if(x != ' ') {
                tempWord += x;
            } else if(!tempWord.empty()) { // Only process if tempWord has content
                tempString = tempWord + (first ? "" : " ") + tempString;
                tempWord = "";
                first = false;
            }
        }
        // Handle the last word
        if(!tempWord.empty()) {
            tempString = tempWord + (first ? "" : " ") + tempString;
        }
        
        return tempString;
    }
};