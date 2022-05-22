/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 16, 2022, 4:56 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;
double fact(int num){
    if(num == 0) return 1;
    if(num == 1) return num;
    return fact(num-1)*num;
}

double comb(int n, int m){
    return fact(n)/fact(n-m)/fact(m);
}
int main(int argc, char** argv) {
    
    int numFaces = 13;
    int numSuits = 4;
    int totalCards = 52;
    
    cout << "Calculate the probability of : \n";
    cout << " \t 1: 1 Pair\n";
    cout << " \t 2: 2 Pair\n";
    cout << " \t 3: 3 of a Kind\n";
    cout << " \t 4: 4 of a Kind\n";
    cout << " \t 5: Quit\n";
    
    int choice;
    cin >> choice;
    
    switch(choice){   
        case 1:
            cout << "\tProbability is: " << comb(numFaces,1)*comb(numSuits,2)*comb(numFaces-1,2)*comb(numSuits,1)*comb(numSuits,1) /comb(totalCards,4)* 100 << "%";
            break;
        case 2:
            cout << "\tProbability is: " << comb(numFaces,2)*comb(numSuits,2)*comb(numSuits,2)/comb(totalCards,4)* 100 << "%";
            break;
        case 3:
            cout << "\tProbability is: " << comb(numFaces,1)*comb(numSuits,3)*comb(numSuits,1)*comb(numFaces-1,1)/comb(totalCards,4)* 100 << "%";
            break;
        case 4:
            cout << "\tProbability is: " << comb(numFaces,1)*comb(numSuits,4)/comb(totalCards,4) * 100 << "%";
            break;
        case 5:
            exit(0);          
    }
    return 0;
}