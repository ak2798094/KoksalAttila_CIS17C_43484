/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Purpose: Singularly Linked List
 * Date Completed: May 6, 2022, 6:45 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <new>

using namespace std;

template <class T>
class LinkedList{
protected:
    struct Link{
        T data;
        Link *lnkNext;
    };
    
    Link *head;
    int size;
public:
    LinkedList()
    {
     head = NULL;
     size = 0;
    }
  
     ~LinkedList()
     {
       while(head!=NULL)
       {
           Link *temp = head;
           head=head->lnkNext;
           delete temp;
        }
         
     }
     
     int getListSize()
     {
         return size;
     }
    
     LinkedList(const LinkedList<T> &list)
     {
         Link *current = 0;
         Link *next = 0;
         
         if(list.head == 0)
         {
             head = 0;
             return;
         }
         
         else
         {
             head = new Link;
             head->data = list.head->data;
             
             current = head;
             next = list.head->lnkNext;
         }
         
         while(next)
         {
             current->lnkNext = new Link;
             current = current->lnkNext;
             current->data = next->data;
             next = next->lnkNext;
         }
         current->lnkNext = 0;
      
     }
     
    void push_front(T val)
    {
        Link *newLink = (Link*)malloc(sizeof(Link));
        newLink->data = val;
        newLink->lnkNext = NULL;
        
        if(head == NULL)
        {
            head = newLink;
        }
        else
        {
            newLink->lnkNext = head;
            head = newLink;
        }
        size++;
         
    }
     
     
    void push_back(T val)
    {
         Link *newLink = (Link*)malloc(sizeof(Link));
         newLink->data = val;
         newLink->lnkNext = NULL;
    //If list is empty, make head the new Link
        if(head == NULL)
            {
                head = newLink;
                size++;
                return;
            }
        Link *last = head;
        while(last->lnkNext != NULL)
        {
            last = last->lnkNext;
        }
        last->lnkNext = newLink;
        size++;
    }
   
    
    T pop_back()
    {
      if(head != NULL)
       {
        Link *current = head;
        Link *prev = NULL;
         
        if(current->lnkNext == NULL)
        {
            T val = current->data;
            //cout << "\n Removed back link: " << current->data << endl;
            head = head->lnkNext;
            size--;
            delete current;
            return val;
        }
        
        while(current->lnkNext != NULL)
        {
            prev = current;
            current = current->lnkNext;
        }
          if(prev == NULL)
          {head = NULL;}
         else
         {
            prev->lnkNext = current->lnkNext;
            T newval = current->data;
            //cout << "Popping off " << current->data << " from the back." << endl;
           delete current;
           size--;
           return newval;
         }
       }
      else
      {
          cout << "There are no links to delete." << endl;
      }
      return 0;
    }
    
    
    T pop_front()
    {
         if(head != NULL)
        {
            Link *temp = head;
            head = head->lnkNext;
            T val = temp->data;
            size--;
            delete temp;
            return val;
            //cout << "Popping off " << temp->data << " from the front." << endl; 
        }
        else
        {
            cout << "There are no links to remove." << endl;
        }
         return 0;
    }
   
    void printLst()
    {
        Link *temp = head;
        if(temp == NULL)
        {
            cout << "No links to display\n";
            return;
        }
        
        cout << "\nPrinting the Link Elements\n";
        while(temp!= NULL)
        {
            cout << temp->data << "  ";
            temp = temp->lnkNext;
        }
        cout << endl;  
    }
    
     
    void insertPos(int pos, T val)
    {
        int newpos = 0;
        Link *newlink = (Link*)malloc(sizeof(Link));
        newlink->data = val;
        newlink->lnkNext = NULL;
        Link *temp = head;
        Link *prev = NULL;
        
        if(pos == 0)
        {
            push_front(val);
            return;
        }
        else if(pos >= getListSize() )
        {
            push_back(val);
            return;
        }
        else
        {
              while(temp != NULL && newpos != pos)
            {
                  prev = temp;
                  temp = temp->lnkNext;
                  newpos++;
            }
             
             prev->lnkNext = newlink;
             newlink->lnkNext = temp;
        } 
        size++;
    } 
     
    int searchList(T val)
    {
        int pos = 0;
        Link *temp = head;
        
        if(temp->data == val)
        {
            return pos;
        }
        
        while(temp != NULL && temp->data != val)
        {
            temp = temp->lnkNext;
            pos++;
        }
        if(temp == NULL)
        {
            cout << "The value of " << val << " could not be found!" << endl;
            return 0;
        }
        return pos;
        
    }
     
    
   T& getter(int pos) const
    {
         if(pos > size-1)
        {
            cout << "That position is out of bounds" << endl;
            exit(EXIT_FAILURE);
        }
        
       Link *current = head;
       while(current != NULL && pos-- > 0)
       {
           current = current->lnkNext;
       }
       
       return current->data;
    }
    
      
};

   
template <class T>
class SimpleVector
{
private:
   LinkedList<T> *link;          // To point to the allocated array
   // Number of elements in the array
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   SimpleVector()
      { link = NULL;}
      
   // Constructor declaration
   SimpleVector(int);
   
   // Copy constructor declaration
   SimpleVector(const SimpleVector &);
   
   // Destructor declaration
   ~SimpleVector();
   
   // Accessor to return the array size
   int size() const
      { return link->getListSize(); }

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

//*******************************************
//Student to code these functions
//*******************************************

template <class T>
void SimpleVector<T>::pshFrnt(T val)
{
    link->push_front(val);
}


template <class T>
void SimpleVector<T>::pshBack(T val)
{
      link->push_back(val); 
}

template <class T>
T SimpleVector<T>::popFrnt()
{
   //Student Code Here
    return link->pop_front();
}

template <class T>
T SimpleVector<T>::popBack()
{
   //Student Code Here
    return link->pop_back();
}

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
   // Allocate memory for the array.
   try
   {
      link = new LinkedList<T>;
   }
   catch (bad_alloc)
   {
      memError();
   }

}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
   // Copy the array size.
   
   // Allocate memory for the array.
   link = new LinkedList<T>;
   if(link == nullptr)
        memError();
      
   // Copy the elements of obj's array.
   link = obj.link;
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
    delete link;
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
   if (sub < 0 || sub >= link->getListSize())
      subError();
   return link->getter(sub);
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= link->getListSize())
      subError();
   return link->getter(sub);
}


//Global Constants

//Function prototypes
int mrkRand(int seed=0);
void fillVec(SimpleVector<char> &,int);
void prntVec(SimpleVector<char> &,int);


int main(int argc, char** argv) 
{

     int size;
    cout<<"Input the Size of the Array 10-100"<<endl;
    cin>>size;
    cout<<"The array Size = "<<size<<endl;
    SimpleVector<char> sv(size);
    
    //Fill the Vector
    fillVec(sv,size);
    
    //Print the Vector
    prntVec(sv,10);
    
     //Add a value to the array
    char vlFrnt=mrkRand()%26+65;
    char vlBack=mrkRand()%26+65;
    cout<<"The value added to the front is = "<<vlFrnt<<endl;
    cout<<"The value added to the back  is = "<<vlBack<<endl;
    sv.pshFrnt(vlFrnt);
    sv.pshBack(vlBack);
    
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

void fillVec(SimpleVector<char> &sv, int size){
    for(int i=0;i<size;i++){
        sv.pshBack(mrkRand(size)%26+65);
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