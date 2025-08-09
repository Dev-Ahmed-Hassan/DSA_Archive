#include <vector>
using namespace std;
#include <string>
class Solution {
public:
    string join(const vector<string>& items) {
    string result;
    for (const auto& item : items) {
        result += item;
    }
    return result;
}
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        if(join(word1) == join(word2)) return true;
        return false;
    }
};