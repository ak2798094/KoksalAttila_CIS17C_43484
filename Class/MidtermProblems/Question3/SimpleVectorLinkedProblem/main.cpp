/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 16, 2022, 2:30 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <chrono>
using namespace std;
int opeq,oplus,opinc,oplt,opstar,opequals,opnot,oppointer;
//User Libraries
#include "Object.h"       //2D Object
#include "SimpleVector.h" //Simple Vector only works with Classes

//Global Constants

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    int SIZE = 50000;
    //Test an object
    Object b(4);
    //Create a Simple Vector using Linked Lists
    SimpleVector<Object> svp(b);
       
    for(int i=0;i<SIZE-1;i++){
       svp.push(b);
       cout << endl;
    }
    
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    svp.push(b);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    
    cout << "Time it took for SimpleVector Push with List of size " << SIZE << " in microseconds: " << std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count() << "ms" << endl << endl;

    //Exit*/
    return 0;
}
