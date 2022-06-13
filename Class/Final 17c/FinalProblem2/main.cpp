/** 
 * @file:   main.cpp
 * @author: Attila Koksal
 * @date: Created on June 9, 2022, 8:40 PM
 * Purpose:  Problem 2 
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
int number_of_h=0;
int number_of_g=0;
float g(float angle);

float h(float angle){
    number_of_h++;
    float t = 1e-6;
    if (angle > -t && angle < t)
    return angle + angle * angle * angle / 6;
    return 2 * h(angle / 2) * g(angle / 2);
}
float g(float angle){
    number_of_g++;
    float t = 1e-6;
    if (angle > -t && angle < t)
    return 1 + angle * angle / 2;
    float bd = h(angle / 2);
    return 1 + 2 * bd * bd;
}

int main(int argc, char **argv){
    float angDeg = 46;
    float angRad = angDeg * atan(1) / 45;
    number_of_g=0;
    number_of_h=0;
    cout << "Angle = " << angDeg << " sinh = " << sinh(angRad) << " our h = " << h(angRad) << endl;
    cout<<"h\t"<<number_of_h<<endl<<"g\t"<<number_of_g<<endl;
    number_of_g=0;
    number_of_h=0;
    cout << "Angle = " << angDeg << " cosh = " << cosh(angRad) << " our g = " << g(angRad) << endl;
    cout<<"h\t"<<number_of_h<<endl<<"g\t"<<number_of_g<<endl;
    return 0;
}