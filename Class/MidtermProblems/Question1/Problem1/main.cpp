/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 15, 2022, 5:30 PM
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

int opeq,opinc,oplus,opmin,oplt,opgt,opindex,opdec,opdiv,opequals,oplteq;
//User Libraries Here

//Function Prototypes Here
void prntAry(const int [],int,int);
void fillAry(int [],int,int,int);
void swap(int &,int &);
void smlLst(int [],int,int);
void mrkSort(int [],int);
int  linSrch(int [],int, int);
int  binSrch(int [],int, int);
void copyAry(int [],int [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
     int SIZE=100;
    int array[SIZE],brray[SIZE];
    int lowRng=0,highRng=SIZE;
    int perLine=10;
        
    //Finish initializing the rest of the array
    fillAry(array,SIZE,highRng,lowRng);
    
    //Linear Search Timing and Operational Analysis
    int value=rand()%(highRng-lowRng+1)+lowRng;
    
    cout<<"Using the Linear Search"<<endl;
    
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    linSrch(array,SIZE,value);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    
    cout << "Time it took for Linear Search with array of size " << SIZE << " in seconds: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << "ns" << endl << endl;
       
    cout << "Linear Search Op Analysis: " << endl;        
    cout<<"N = Size to Search      = "<<SIZE<<endl;
    cout<<"Operator equal        = "<<opeq<<" times"<<endl;
    cout<<"Operator minus        = "<<opmin<<" times"<<endl;
    cout<<"Operator division = "<<opdiv<<" times"<<endl;
    cout<<"Operator less than    = "<<oplt<<" times"<<endl;
    cout<<"Operator less than equal to = "<<oplteq<<" times"<<endl;
    cout<<"Operator ++           = "<<opinc<<" times"<<endl;
    cout<<"Operator add          = "<<oplus<<" times"<<endl;
    cout<<"Operator index        = "<<opindex<<" times"<<endl;
    cout<<"Operator greater than = "<<opgt<<" times"<<endl;
    cout<<"Operator Equals Equals = "<<opequals<<" times"<<endl;
    cout<<"Total Operations      = "<<opeq+opmin+oplt+opinc+oplus+opindex+opgt+oplteq+opdiv+opequals<<" times"<<endl << endl;
    
    
    //Binary Search Timing and Operational Analysis
    
    mrkSort(array,SIZE);
    cout<<"Using the Binary Search"<<endl;
    
    std::chrono::steady_clock::time_point nbegin = std::chrono::steady_clock::now();
    binSrch(array,SIZE,value);
    std::chrono::steady_clock::time_point nend = std::chrono::steady_clock::now();
    
    cout << "Time it took for Binary Search with array of size " << SIZE << " in seconds: " << std::chrono::duration_cast<std::chrono::nanoseconds>(nend-nbegin).count() << "ns" << endl << endl;
    
    cout << "Binary Search Op Analysis: " << endl;        
    cout<<"N = Size to Search      = "<<SIZE<<endl;
    cout<<"Operator equal        = "<<opeq<<" times"<<endl;
    cout<<"Operator minus        = "<<opmin<<" times"<<endl;
    cout<<"Operator division = "<<opdiv<<" times"<<endl;
    cout<<"Operator less than    = "<<oplt<<" times"<<endl;
    cout<<"Operator less than equal to = "<<oplteq<<" times"<<endl;
    cout<<"Operator ++           = "<<opinc<<" times"<<endl;
    cout<<"Operator add          = "<<oplus<<" times"<<endl;
    cout<<"Operator index        = "<<opindex<<" times"<<endl;
    cout<<"Operator greater than = "<<opgt<<" times"<<endl;
    cout<<"Operator Equals Equals = "<<opequals<<" times"<<endl;
    cout<<"Total Operations      = "<<opeq+opmin+oplt+opinc+oplus+opindex+opgt+oplteq+opdiv+opequals<<" times"<<endl;

    //Exit
    return 0;
}
void copyAry(int copyIt[],int source[],int n){
    for(int i=0;i<n;i++){
        copyIt[i]=source[i];
    }
}
int  binSrch(int a[],int n, int val){
    //Initialize end points which are indexes
    int lowEnd=0;
    int highEnd=n-1;
    opeq+=2;
    opmin+=1;
    //Loop until value found not indexes
    do{
        opeq+=1;
        oplus+=1;
        opdiv+=1;
        int middle=(highEnd+lowEnd)/2;
        
        opindex+=1;
        opequals+=1;
        if(val==a[middle])
        {return middle;}
        
        opgt+=1;
        opindex+=1;
        if(val>a[middle])
        {
            opeq+=1;
            oplus+=1;
            lowEnd=middle+1;
        }
        
        else 
        {
            opeq+=1;
            opmin+=1;
            highEnd=middle-1;
        }
        oplteq+=1;
    }while(lowEnd<=highEnd);
    
    //Not found
    return -1;
}
int  linSrch(int a[],int n, int val){
    
    opeq+=1;
    for(int indx=0;indx<n;indx++)
    {
       opinc+=1;
       oplt+=1;
       opequals+=1;
       opindex+=1;
        if(val==a[indx])return indx;
    }
    return -1;
}
void fillAry(int a[],int n,int hr,int lr){
    for(int indx=0;indx<n;indx++){
        a[indx]=rand()%(hr-lr+1)+lr;
    }
}
void prntAry(const int a[],int n,int perLine){
    //Print the values in the array
    cout<<endl<<"The Array Values"<<endl;
    for(int indx=0;indx<n;indx++){
        cout<<a[indx]<<" ";
        if(indx%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}
void mrkSort(int a[],int n){
    for(int pos=0;pos<n-1;pos++){
        smlLst(a,n,pos);
    }
}
void smlLst(int a[],int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(a[pos]>a[i]){
            swap(a[pos],a[i]);
        }
    }
}
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}