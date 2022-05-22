/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 19, 2022, 6:45 PM
 */

//Libraries
#include <cstdlib>//Random number seed
#include <ctime>//Set the seed
#include <iostream>//I/O
#include <iterator>
#include <algorithm>
#include <set>
using namespace std;

//No Global Constants

//Function Prototype
void prntMod(int *);
int *mode(const multiset<int> &,int);

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables and fill
    int arySize=11;
    int modNum=10;
    int perLine = 10;
    
    multiset<int> set;
    
     for(int i=0;i<arySize;i++){
        set.insert(i%modNum);
    }

    int i = 0;
    for(auto iter = set.begin(); iter != set.end();++iter)
    {
        cout << *iter << " ";
        if(i%perLine==(perLine-1))cout<<endl;
        i++;
    }
  
    //Calculate the mode array
    int *modeAry=mode(set,arySize);
    
    //Print the modal information of the array
    prntMod(modeAry);
   
    //Delete allocated memory
   
    delete []modeAry;
    
    //Exit stage right
    return 0;
}

int *mode(const multiset<int> &set,int arySize){
    //Find the max Freq
    int count=0,maxFreq=0;
    for(int i=0;i<arySize-1;i++){
        if(*next(set.begin(),i)==*next(set.begin(),i+1)){
            count++;
            if(maxFreq<count)maxFreq=count;
        }else{
            count=0;
        }
    }
    //Find the number of modes
    count=0;
    int nModes=0;
    for(int i=0;i<arySize-1;i++){
        if(*next(set.begin(),i)==*next(set.begin(),i+1)){
            count++;
            if(maxFreq==count)nModes++;
        }else{
            count=0;
        }
    }
    //Allocate the mode array
    int *modeAry=new int[nModes+2];
    //Fill the mode array
    modeAry[0]=nModes;
    modeAry[1]=maxFreq+1;
    count=0;
    int indx=2;
    for(int i=0;i<arySize-1;i++){
        if(*next(set.begin(),i)==*next(set.begin(),i+1)){
            count++;
            if(maxFreq==count)modeAry[indx++]= *next(set.begin(),i);
        }else{
            count=0;
        }
    }
    //Delete the allocated copy and return
    return modeAry;
}
void prntMod(int *ary){
    cout<<endl;
    cout<<"The number of modes = "<<ary[0]<<endl;
    cout<<"The max Frequency = "<<ary[1]<<endl;
    if(ary[0]==0){
        cout<<"The mode set = {null}"<<endl;
        return;
    }
    cout<<"The mode set = {";
    for(int i=2;i<ary[0]+1;i++){
        cout<<ary[i]<<",";
    }
    cout<<ary[ary[0]+1]<<"}"<<endl;
}