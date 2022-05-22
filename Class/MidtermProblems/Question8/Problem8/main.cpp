/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 16, 2022, 8:30 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;
const int LOOP = 10000;
int main(int argc, char** argv) {
    srand(time(0));
    int i = 0;
    int hit = 0;
    double prob = 0;
    
    while(i < LOOP)
    {
        int bit1 = rand()%100+1;
        int bit2 = rand()%100+1;
        int bit3 = rand()%100+1;
        int bit4 = rand()%100+1;
        int bit5 = rand()%100+1;
        
        if(bit1 <= 40 && bit2 <= 40 && bit3 <= 40 && bit4 <= 40 && bit5 <= 40)
        {
            hit++;
        }
        i++;
        
    }
    prob = (double)hit/LOOP;
    cout << "The probability of falling in an area that is 40% full is: " << prob << endl;
    return 0;
}