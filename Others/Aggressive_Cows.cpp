#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int>& stalls, int mid, int k) {
    int cowsPlaced = 1;
    int lastPos = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPos >= mid) {
            cowsPlaced++;
            lastPos = stalls[i];
            if (cowsPlaced == k) return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int>& stalls, int k) {
    sort(stalls.begin(), stalls.end());
    
    if (k > stalls.size()) return -1;
    if (k == stalls.size()) return stalls.back() - stalls[0];

    int start = 0;
    int end = stalls.back() - stalls[0];
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (isPossible(stalls, mid, k)) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}