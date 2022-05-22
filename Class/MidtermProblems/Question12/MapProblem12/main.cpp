/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 18, 2022, 3:35 PM
 */

//Libraries
#include <cstdlib>//Random number seed
#include <ctime>//Set the seed
#include <iostream>//I/O
#include <iterator>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
using namespace std;

//No Global Constants

//Function Prototype
void mode(map<int, multiset<int> > &,int);
//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables and fill
    int arySize=20;
    int modNum=10;
    int perLine = 10;
    map<int, multiset<int> > modeMap;

    for(int i=0;i<arySize;i++){
         modeMap[0].insert(i%modNum);
    }
 
    int i = 0;
    cout << "The Sorted Values: " << endl;
    for(auto elem : modeMap[i]){
        cout<<elem<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
        i++;
    }
    
     mode(modeMap,modNum);
    //Exit stage right
    return 0;
}

void mode(map<int,multiset<int> > &modeMap, int modNum){
    int nmodes;
    map<int, vector<int> > mapvec;
    for(int i = 0; i < modNum; i++){
        modeMap[0].count(i);
        mapvec[0].push_back(modeMap[0].count(i));
    }
    
    //Find the max Freq
    int maxFreq = *max_element(mapvec[0].begin(),mapvec[0].end());
    
    if(count(mapvec[0].begin(),mapvec[0].end(),maxFreq) == 1){
        nmodes = 1;
    }
    if(count(mapvec[0].begin(),mapvec[0].end(),maxFreq) > 1){
        nmodes =  count(mapvec[0].begin(),mapvec[0].end(),maxFreq);
    }
    
    if(maxFreq == 1){
        nmodes = 0;
    }
   
    cout<<endl;
    cout<<"The number of modes = "<<
            nmodes<<endl;
    cout<<"The max Frequency = "<<
            maxFreq <<endl;
    if(nmodes==0){
        cout<<"The mode set = {null}"<<endl;
        return;
    }
    
    auto iter = find(mapvec[0].begin(),mapvec[0].end(),maxFreq);
    cout<<"The mode set = {";
    if(count(mapvec[0].begin(),mapvec[0].end(),maxFreq) == 1){
        cout<<iter-mapvec[0].begin()<< "}"<<endl;
        return;
    }
    while(*iter == maxFreq){
        cout<<iter-mapvec[0].begin()<<","; 
        iter++;
    }
    cout <<"}"<<endl;  
}