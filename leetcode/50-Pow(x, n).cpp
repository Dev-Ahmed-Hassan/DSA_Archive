#include <cmath>
using namespace std;
#include<vector>

// Approach: Efficient exponentiation by squaring
// This method reduces the time complexity to O(log n) by using bit manipulation.
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;  // Avoid overflow when n = INT_MIN
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double ans = 1.0;
        while (N > 0) {
            if (N & 1) {  // If LSB is 1
                ans *= x;  // Multiply current power of x
            }
            x *= x;  // Square x for the next bit
            N >>= 1; // Right-shift N (divide by 2)
        }
        return ans;
    }
};


// You are a clown if you use this solution, but it works.
class Solution {
public:
    double myPow(double x, int n) {
        return pow(x,n);
    }
};


// This is a simple solution, but it is not efficient.

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 || x==1)
        {
            return 1;
        }
        if(n==1) return x;
        if(n < 0){
            x = 1/x;
        }
        
        double temp = x;
        long long pow = (n > 0) ? n : -1LL * n;  
        long long cpow=1;
        while(cpow < pow)
        {
            temp*=temp;
            cpow*=2;
        }
        if(cpow == pow) return temp;
        else{
            for(int i= 0; i<cpow-pow; i++)
            {
                temp/=x;
            }
            return temp;
        }
        return -1;
    }
};