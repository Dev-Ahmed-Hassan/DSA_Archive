#include<iostream>
#include<vector>
#include<climits>

using namespace std;
class Solution {
public:
    pair<int, int> Calculate(string s) {
        int space = 0;
        int wrd = 0;
        string word = "";
        for (char x : s) {
            if (x == ' ') {
                space++;
                if (!word.empty()) {
                    word = "";
                    wrd++;
                }
            } else {
                word += x;
            }
        }
        if (!word.empty()) {
            wrd++;
        }
        return {space, wrd};
    }

    string reorderSpaces(string text) {
        auto [totalSpaces, wordCount] = Calculate(text);
        
        // Handle edge case: only one word
        if (wordCount == 1) {
            string result;
            // Find the word
            for (char c : text) if (c != ' ') result += c;
            // Add all spaces at the end
            result += string(totalSpaces, ' ');
            return result;
        }
        
        int spaceBetween = totalSpaces / (wordCount - 1);
        int extraSpaces = totalSpaces % (wordCount - 1);
        
        string result;
        string word;
        bool firstWord = true;
        
        for (char c : text) {
            if (c == ' ') {
                if (!word.empty()) {
                    if (!firstWord) {
                        result += string(spaceBetween, ' ');
                    }
                    result += word;
                    word.clear();
                    firstWord = false;
                }
            } else {
                word += c;
            }
        }
        
        // Add last word
        if (!word.empty()) {
            if (!firstWord) {
                result += string(spaceBetween, ' ');
            }
            result += word;
        }
        
        // Add remaining spaces
        result += string(extraSpaces, ' ');
        
        return result;
    }
};