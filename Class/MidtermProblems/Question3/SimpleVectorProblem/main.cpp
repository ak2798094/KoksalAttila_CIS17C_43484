/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 16, 2022, 10:30 AM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <chrono>
using namespace std;
int opeq,oplus,opindex,opinc,oplt,opstar;
//User Libraries
#include "Object.h"       //2D Objects
#include "SimpleVector.h" //Simple Vector only works with Classes

//Global Constants


//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Test an object
    int SIZE = 5000;
    Object b(5);
    SimpleVector<Object> svp(SIZE);
   
    cout << "Arraysize is: " << svp.size() << endl;
    
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    svp.push(b);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    
    cout << "Time it took for SimpleVector Push with Object of size " << SIZE << " in microseconds: " << std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count() << "ms" << endl << endl;
  
    //Exit
    return 0;
}
