/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Purpose:  To Test and Modify the Simple Vector
 * Date Completed: May 6, 2022, 2:50 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <new>  // Needed for bad_alloc exception
using namespace std;
    
template <class T>
class SimpleVector
{
private:
   T *aptr;          // To point to the allocated array
   int arraySize;
   int maxSize;// Number of elements in the array
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   SimpleVector()
      { aptr = 0; arraySize = 0; maxSize = 0;}
      
   // Constructor declaration
   SimpleVector(int);
   
   // Copy constructor declaration
   SimpleVector(const SimpleVector &);
   
   // Destructor declaration
   ~SimpleVector();
   
   // Accessor to return the array size
   int size() const
      { return arraySize; }

   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);
   
   //Adding 4 functions Push front/back, Pop front/back
   void pshFrnt(T);
   void pshBack(T);
   T popFrnt();
   T popBack();
};

template <class T>
void SimpleVector<T>::pshFrnt(T val)
{
    if(arraySize == maxSize) //If the array is full
    {
        if(maxSize > 0)
           maxSize *= 2;
        else
            maxSize = 2;
        
        
        T* newArray = new T[maxSize];
        
        for(int i = 0; i < arraySize; i++)
        {
            newArray[i+1] = aptr[i];
        }
        newArray[0] = val;
        
        delete[] aptr;
        aptr = newArray;
    }
    else
    {
        for(int i = arraySize; i > 0; i--)
        {
            aptr[i] = aptr[i-1];
        }
        aptr[0] = val;
    }
    arraySize++;
}


template <class T>
void SimpleVector<T>::pshBack(T val)
{
   if(arraySize == maxSize) //If the array is full
    {
       if(maxSize > 0)
        maxSize *= 2;
       else
           maxSize = 2;
        
        T* newArray = new T[maxSize];
        
        for(int i = 0; i < arraySize; i++)
        {
            newArray[i] = aptr[i];
        }
        newArray[arraySize] = val;
        
        delete[] aptr;
        aptr = newArray;
    }
    else
    {
        aptr[arraySize] = val;
    }
    arraySize++;
        
}

template <class T>
T SimpleVector<T>::popFrnt()
{
    T val = 0;
    if(arraySize > 0)
    {
        val = *aptr;
        for(int i = 1; i < arraySize-1;i++)
        {
            aptr[i-1] = aptr[i];
        }
            arraySize--;
    }
    if(arraySize == maxSize/4)
    {
        if(maxSize > 1)
             maxSize /= 2;
        
        T* newArray = new T[maxSize];
        
       for(int i = 0; i < arraySize; i++)
        {
            newArray[i] = aptr[i];
        }
        delete [] aptr;
        aptr = newArray;
        
    }
    return val;
     
}
    
template <class T>
T SimpleVector<T>::popBack()
{
    T val = 0;
    
    if(arraySize > 0)
    {
        val = *(aptr + arraySize +1);
        arraySize--;
    }
    if(arraySize == maxSize/4)
    {
        if(maxSize > 1)
        {maxSize /= 2;}
        
        T* newArray = new T[maxSize];
        
       for(int i = 0; i < arraySize; i++)
        {
            newArray[i] = aptr[i];
        }
        
        delete [] aptr;
        aptr = newArray;
        
    }
    return val;
 
}
   
//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
   arraySize = s;
   maxSize = s;
   // Allocate memory for the array.
   try
   {
      aptr = new T [s];
   }
   catch (bad_alloc)
   {
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < arraySize; count++)
      *(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
   // Copy the array size.
   arraySize = obj.arraySize;
   
   // Allocate memory for the array.
   aptr = new T [arraySize];
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
   if (arraySize > 0)
      delete [] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}


//Global Constants

//Function prototypes
int mrkRand(int seed=0);
void fillVec(SimpleVector<char> &);
void prntVec(SimpleVector<char> &,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int size;
    cout<<"Input the Size of the Array 10-100"<<endl;
    cin>>size;
    cout<<"The array Size = "<<size<<endl;
    SimpleVector<char> sv(size);
    
    //Fill the Vector
    fillVec(sv);
   
    sv.pshFrnt('B');
    sv.pshBack('X');
    sv.pshFrnt('L');
    sv.pshBack('Y');
    sv.pshBack('N');
    sv.pshFrnt('G');
    
    //Print the Vector
    prntVec(sv,10);
    
    //Remove 2 from the Front and 2 from the back
    
    cout<<endl;
    cout<<"Remove 2 from the front and back"<<endl;
    cout<<"Front Removed = "<<sv.popFrnt()<<endl;
    cout<<"Front Removed = "<<sv.popFrnt()<<endl;
    cout<<"Back  Removed = "<<sv.popBack()<<endl;
    cout<<"Back  Removed = "<<sv.popBack()<<endl;
  
    
    //Print the Vector
    prntVec(sv,10);

    return 0;
}

void prntVec(SimpleVector<char> &sv,int perLine){
    cout<<endl;
    for(int i=0;i<sv.size();i++){
        cout<<sv[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void fillVec(SimpleVector<char> &sv){
    for(int i=0;i<sv.size();i++){
        sv[i]=mrkRand(sv.size())%26+65;
    }
}

int mrkRand(int seed){
    //Xn+1 = (aXn + c) mod m
    //where X is the sequence of pseudo-random values
    //m, 0 < m  - modulus 
    //a, 0 < a < m  - multiplier
    //c, 0 ≤ c < m  - increment
    //x0, 0 ≤ x0 < m  - the seed or start value
    unsigned int a=31051;      //Short Prime
    unsigned int c=997;        //Another Prime
    unsigned int shrt=1<<15-1; //Range of positive signed short
    unsigned int m=1<<31-1;    //Range of positive signed int
    static int Xn=30937;       //Short Prime
    static int cnt=0;          //Initialize the seed
    if(cnt==0&&seed<=shrt)Xn=seed;
    cnt++;
    Xn=(a*Xn+c)%m;
    return Xn;
}