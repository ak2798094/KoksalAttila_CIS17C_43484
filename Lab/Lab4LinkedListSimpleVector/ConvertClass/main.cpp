/*
    Author: Dr. Mark E. Lehr
    Date:   March 29th, 2021  1:12pm
    Purpose: Converted into a class
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <cstdlib>//NULL pointer
#include <ctime>
using namespace std;   //Library Name-space

//User Libraries

class LinkedList{
private:
    struct Link{
        int data;
        Link *lnkNext;
    };
    
    Link *head;
public:
    LinkedList()
    {head = NULL;}
    
     ~LinkedList()
     {
       while(head!=NULL)
       {
           Link *temp = head;
           head=head->lnkNext;
           delete temp;
        }
         
     }
    
    void push_front(int val)
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
         
    }
    
    void push_back(int val)
    {
         Link *newLink = (Link*)malloc(sizeof(Link));
         newLink->data = val;
         newLink->lnkNext = NULL;
    //If list is empty, make head the new Link
        if(head == NULL)
            {
                head = newLink;
                return;
            }
        Link *last = head;
        while(last->lnkNext != NULL)
        {
            last = last->lnkNext;
        }
        last->lnkNext = newLink;
    }
   
    
    void pop_back()
    {
      if(head != NULL)
       {
        Link *current = head;
        Link *prev = NULL;
        
        if(current->lnkNext == NULL)
        {
            cout << "\n Removed back link: " << current->data << endl;
            head = head->lnkNext;
            delete current;
            return;
        }
        
        while(current->lnkNext != NULL)
        {
            prev = current;
            current = current->lnkNext;
        }
          if(prev == NULL)
            head = NULL;
         else
            prev->lnkNext = current->lnkNext;
            cout << "Popping off " << current->data << " from the back." << endl;
           delete current;
       }
      else
      {
          cout << "There are no links to delete." << endl;
      }
   
    }
    
    void pop_front()
    {
         if(head != NULL)
        {
            Link *temp = head;
            head = head->lnkNext;
            cout << "Popping off " << temp->data << " from the front." << endl; 
            delete temp;    
        }
        else
        {
            cout << "There are no links to remove." << endl;
        }
        
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
    
    

};


//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    srand(time(NULL));
    
    LinkedList list;
    list.push_back(2);
    list.push_back(3);
    list.push_back(5);
    list.push_front(-2);
    list.push_front(12);
    list.push_back(20);
    list.push_front(15);
    list.push_back(0);
    
    list.printLst();
    cout << endl;
    list.pop_back();
    list.pop_front();
    list.printLst();
    
    //list.destroyList();
    
    //Exit stage right
    return 0;
}
