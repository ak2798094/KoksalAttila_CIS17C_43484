/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Purpose: Permutation Combination Comparison
 * Created on April 26, 2022, 2:40 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Global Constants

//Function Prototypes
float fact(float);

int main(int argc, char** argv) {
    
    float n=2;
    float m=0;
    
    cout<<"n"<<setw(4)<<"m"<<setw(15)<<"Permutation"<<setw(15)<<"Permutation"<<setw(15)<<"Combination"<<setw(15)<<"Combination "<<endl;
    cout<<setw(20)<<"Replacement"<<setw(30)<<"Replacement"<<endl;
    m++;
    while(n<=26){
        cout<<left<<setw(2)<<n<<"  "<<setw(2)<<m<<"\t\t";
        cout<<left<<setw(11)<<pow(n,m)<<"\t";
        cout<<left<<setw(11)<<fact(n)/fact(n-m)<<"\t";
        cout<<left<<setw(11)<<fact(n+m-1)/fact(n-1)/fact(m)<<"\t";
        cout<<left<<setw(11)<<fact(n)/fact(n-m)/fact(m)<<endl;
        if(m==n){
            m=0;
            n++;
        }
        m++;
    }
    return 0;
}
float fact(float num){
    if(num==0) return 1;
    if(num<=1) return num;
    return fact(num-1)*num;
}