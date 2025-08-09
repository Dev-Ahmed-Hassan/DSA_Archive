#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &rank, int mid, int m) {
    int totalDishes = 0;
    for(int i = 0; i < rank.size(); i++) {
        int time = 0;
        int dishes = 0;
        int multiplier = 1;
        while(true) {
            time += multiplier * rank[i];
            if(time > mid) break;
            dishes++;
            multiplier++;
        }
        totalDishes += dishes;
        if(totalDishes >= m) return true;
    }
    return totalDishes >= m;
}

int minCookTime(vector<int> &rank, int m) {
    sort(rank.begin(), rank.end());
    
    // Calculate upper bound (time taken by worst cook to make all dishes)
    int maxRank = rank.back();
    int e = 0;
    for(int i = 1; i <= m; i++) {
        e += i * maxRank;
    }
    
    int s = 0;
    int ans = -1;
    while(s <= e) {
        int mid = s + (e - s)/2;
        if(isPossible(rank, mid, m)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}