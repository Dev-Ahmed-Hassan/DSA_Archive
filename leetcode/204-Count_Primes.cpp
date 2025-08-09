#include <vector>
using namespace std;


// Using Sieve of Eratosthenes to count primes less than n
// Time Complexity: O(n log log n)
// Space Complexity: O(n)


class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n+1, true);
        int count = 0;
        prime[0] = prime[1] = false;
        for(int i=2; i<n; i++)
        {
            if(prime[i]){
                count++;
                for(int j=2*i; j<n+1; j+=i)
                {
                    prime[j] = false;
                }
            }
        }
        return count;
    }
};