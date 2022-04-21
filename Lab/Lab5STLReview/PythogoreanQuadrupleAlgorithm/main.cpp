/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Purpose:  Pythagorean Quadruple Algorithm
 */

//System Libraries

#include <bits/stdc++.h>

using namespace std;

bool pythagorean_quadruple(int,int,int,int);

int main(int argc, char** argv) {
    
    int a = 1, b = 2, c = 2, d = 3;
    if (pythagorean_quadruple(a, b, c, d))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    return 0;
}
bool pythagorean_quadruple(int a, int b, int c,int d)
{
    int sum = a * a + b * b + c * c;
    if (d * d == sum)
        return true;
    else
        return false;
}