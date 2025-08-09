#include<iostream>
#include<vector>
#include<climits>

using namespace std;
class Solution {
public:

// Function using stack
    string removeOccurrences(string s, string part) {
        string stack;
        for (char c : s) {
            stack.push_back(c);
            if (stack.size() >= part.size() && 
                stack.substr(stack.size() - part.size()) == part) {
                stack.erase(stack.end() - part.size(), stack.end());
            }
        }
        return stack;
    }



    // Function using string;

    string removeOccurrences(string s, string part) {
        bool occuranceFound = true;
        while (occuranceFound) {
            if (part.size() > s.size()) {
                break;
            }
            occuranceFound = false;  
            for (int i = 0; i <= s.size() - part.size(); i++) {  
                string temp = s.substr(i, part.size()); 
                if (temp == part) {
                    s.erase(i, part.size());
                    occuranceFound = true;  
                    break;  
                }
            }
        }
        return s;
    }


// Most Effecient Solution


    string removeOccurrences(string s, string part) {
        // Find the first occurrence of 'part' in 's'
        int i = s.find(part);
        
        // While we keep finding 'part' in 's'
        while(i != string::npos) {
            // Remove the found 'part' from 's'
            s.erase(i, part.length());
            // Look for the next occurrence of 'part'
            i = s.find(part);
        }
        
        // Return the modified string
        return s;
    }

};



