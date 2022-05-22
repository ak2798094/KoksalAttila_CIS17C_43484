/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 17, 2022, 4:25 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

float cFunc(float);
float sFunc(float);

int main(int argc, char** argv) {
    float positive = atan(1);
    float negative = atan(-1);
    
    for(float x = negative; x <= positive; x+=0.1f){
        cout << "x value: " << x << endl;
        cout << "C(2x) = " << cFunc(x) << endl;
        cout << "S(2x) = " << sFunc(x) << endl << endl;
    }
    cout << "x value: " << positive << endl;
    cout << "C(2x) = " << cFunc(positive) << endl;
    cout << "S(2x) = " << sFunc(positive) << endl << endl;
    
    return 0;
}
float cFunc(float x){
    float tol = 1e-6f;
    
    if(abs(x) < tol)
        return (1/x) + x/6;
    return 0.5*cFunc(x/2)*sFunc(x/2);
}
float sFunc(float x){
   float tol = 1e-6f;
   if(abs(x) < tol)
       return 1 + (x*x)/2;
   
   float ctemp = cFunc(x/2);
   float stemp = sFunc(x/2);
   return (ctemp*ctemp*stemp*stemp)/(ctemp*ctemp-stemp*stemp);
    
}