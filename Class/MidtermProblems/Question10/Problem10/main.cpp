/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 17, 2022, 12:35 PM
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

float recFunc(float x){
    float tol = 1e-6f;
    if(abs(x) < tol){
        return x-(x*x*x)/6;
    }
    
    float temp = recFunc(x/2);
    float a = (2*temp)/(1+temp*temp);
    return a;
}

int main(int argc, char** argv) {
    for(float i = -1; i < 1.1; i+=0.1){
        if(floor(i*100+0.5)/100 == 0){
            cout << floor(i*100+0.5)/100 << ": " << "0" << endl;
            i+=0.1;
        }
        cout << floor(i*100+0.5)/100 << ": " << recFunc(i) << endl;
    }
    return 0;
}