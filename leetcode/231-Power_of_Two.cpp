// Approach: Check if a number is a power of two using bit manipulation
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};


// Approach: Check if a number is a power of two using division
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;  // Handle 0 and negative numbers
        
        while (n > 1) {  // Stop when n reaches 1
            if (n % 2 != 0) {
                return false;
            }
            n = n / 2;
        }
        return true;  // If we get to 1, it's a power of two
    }
};


