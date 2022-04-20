/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Purpose:  Pair Container
 */

//System Libraries
#include <iostream>
#include <utility>

using namespace std;

int main(int argc, char** argv) {
    // defining a pair
    pair<int, char> PAIR1;
 
    // first part of the pair
    PAIR1.first = 100;
    // second part of the pair
    PAIR1.second = 'G';
 
    cout << PAIR1.first << " ";
    cout << PAIR1.second << endl;
    
    return 0;
}