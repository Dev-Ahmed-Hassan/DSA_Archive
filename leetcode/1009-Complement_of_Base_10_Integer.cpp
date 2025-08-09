#include <bits/stdc++.h>
#include <cmath>
using namespace std;

// convert to bits, take complement and again convert to number manually. 
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1; // Special case for input 0
        
        string binary = "";
        string bit;
        int ans = 0; // Initialize to 0

        while(n != 0) {
            bit = to_string(n % 2);
            if(bit == "0") bit = "1";
            else bit = "0";
            binary = bit + binary;
            n = n / 2;
        }

        for(int i = 0; i < binary.size(); i++) {
            if(binary[i] == '1') {
                ans += pow(2, binary.size() - 1 - i);
            }
        }
        return ans;
    }
};


// Better solution

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1; // Special case for input 0
        
        int mask = 0;
        int var = n;

        // making the mask according to the required number
        while(var != 0)
        {
            mask = ( mask << 1) | 1;
            var = var >> 1;
        }
        // masking out the required thing only
        int ans = (~n) & mask;
        return ans;
    }
};