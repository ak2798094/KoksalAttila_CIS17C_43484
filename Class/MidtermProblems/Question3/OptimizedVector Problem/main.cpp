/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 16, 2022, 8:58 AM
 */


//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <chrono>
using namespace std;
int opeq,oplus,opindex,opinc,oplt,opstar,opequals = 0;
//User Libraries
#include "Object.h"       //2D Objects
#include "SimpleVector.h" //Simple Vector only works with Classes
 
//Global Constants

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Test an object
    int SIZE = 10;
    Object b(5);
    
    //Test an object by populating the simple vector and print
    SimpleVector<Object> svp(SIZE);
 
    for(int i = 0; i < 100; i++)
    {
    cout << "Arraysize is: " << svp.size() << endl;
    svp.push(b);
    cout << endl;
    cout << "Total Operations for Optimized Vector: " << opindex+opeq+opinc+oplt+opstar+opequals+oplus << endl;
    }
    
    //Exit
    return 0;
}

