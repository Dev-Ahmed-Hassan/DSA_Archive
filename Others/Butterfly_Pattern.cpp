#include<iostream>
using namespace std;

void printButterfly(int n){
    // Upper part of the butterfly
    for(int i = 1; i <= n; i++) {
        // Left stars
        for(int j = 1; j <= i; j++) {
            cout << "*";
        }
        // Spaces in the middle
        for(int j = 1; j <= 2 * (n - i); j++) {
            cout << " ";
        }
        // Right stars
        for(int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    // Lower part of the butterfly
    for(int i = n; i >= 1; i--) {
        // Left stars
        for(int j = 1; j <= i; j++) {
            cout << "*";
        }
        // Spaces in the middle
        for(int j = 1; j <= 2 * (n - i); j++) {
            cout << " ";
        }
        // Right stars
        for(int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}


int main()
{

    printButterfly(2);
    
    return 0;
}