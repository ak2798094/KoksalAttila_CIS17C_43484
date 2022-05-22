/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 17, 2022, 9:30 AM
 */

#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

float powerN(float x, unsigned int n){
    if(n == 0)return 1;
    return powerN(x,n-1)*x;
}
float powerLn(float x, unsigned int n){
    float a;
    if(n == 0) return 1;
    
    a = powerLn(x,n/2);
    if(n%2 == 0){
        return a*a;
    }
    else
        return a*a*x; 
}
int main(int argc, char** argv) {
    
    float x;
    unsigned int n = 1;
    cout << "Enter a value for x: ";
    cin >> x;
    cout << endl;
    
    cout << "Enter a value for n (natural number): ";
    cin >> n;
    cout << endl;
    cout << "Power function using O(logn) recusion: " << powerLn(x,n) << endl;
    cout << "Power function using O(n) recusion: " << powerN(x,n) << endl;

    return 0;
}