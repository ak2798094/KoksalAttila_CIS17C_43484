
/* 
 * File:   main.cpp
 * Author: Attila Koksal
 *
 * Created on May 15, 2022, 10:30 PM
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
void bublSrt(int [],int);
void selSort(int [],int);
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
    copyAry(brray,array,SIZE);
    
    //Selection sort Timing and Operational Analysis
    
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
     selSort(array,SIZE);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    
    cout << "Time it took for Selection Sort with array of size " << SIZE << " in seconds: " << std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count() << "ms" << endl << endl;
    
     cout << "Selection Sort Op Analysis: " << endl;        
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
    cout<<"Total Operations      = "
            <<opeq+opmin+oplt+opinc+oplus+opindex+opgt+oplteq+opdiv+opequals<<" times"<<endl << endl;
    
    
    //Bubble Sort timing and Operational Analysis
    std::chrono::steady_clock::time_point nbegin = std::chrono::steady_clock::now();
    bublSrt(brray,SIZE);
    std::chrono::steady_clock::time_point nend = std::chrono::steady_clock::now();
    
     cout << "Time it took for Bubble Sort with array of size " << SIZE << " in seconds: " << std::chrono::duration_cast<std::chrono::microseconds>(nend-nbegin).count() << "ms" << endl << endl;
    
    cout << "Bubble Sort Op Analysis: " << endl;        
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
    cout<<"Total Operations      = "
            <<opeq+opmin+oplt+opinc+oplus+opindex+opgt+oplteq+opdiv+opequals<<" times"<<endl << endl;

    //Exit
    return 0;
}

void copyAry(int copyIt[],int source[],int n){
    for(int i=0;i<n;i++){
        copyIt[i]=source[i];
    }
}

void selSort(int a[],int n){
    //Loop and declare variables
    int indx,min;
    opeq+=1;
    for(int pos=0;pos<n-1;pos++){
       opmin+=1;
       oplt+=1;
       opinc+=1;
        //Find the smallest in the list, swap after finding
        
       opeq+=3;
       oplus+=1;
       opindex+=1;
        min=a[pos];indx=pos;
        for(int i=pos+1;i<n;i++){
            oplt++;
           opinc++;
            
            opindex++;
            oplt++;
            if(a[i]<min){
                opeq+=2;
                opindex++;
                min=a[i];
                indx=i;
            }
        }
        //Perform the swap
        opindex+=3;
        opeq+=2;
        a[indx]=a[pos];
        a[pos]=min;
    }
}

void bublSrt(int a[],int n){
    //Keep looping and comparing until no swaps are left
    opeq,oplt,opmin,opinc,opgt,oplus,opindex = 0;
    bool swap;
    do{
        opeq+=1;
        swap=false;
        //Check the list and Swap when necessary
        opeq+=1;
        for(int i=0;i<n-1;i++){
            
            oplt+=1;
            opmin+=1;
            opinc+=1;
            
            opindex+=2;
            opgt+=1;
            oplus+=1;
            
            if(a[i]>a[i+1]){
                opeq+=4;
                opindex+=4;
                oplus+=2;
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                swap=true;
            }
        }
    }while(swap);
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
