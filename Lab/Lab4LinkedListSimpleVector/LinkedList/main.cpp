/*
    Author: Dr. Mark E. Lehr
    Date:   March 29th, 2021  1:12pm
    Purpose: Linked List Step #1
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <cstdlib>     //NULL pointer
using namespace std;   //Library Name-space

//User Libraries
struct Link
{
    int data;
    Link *lnkNext;
};

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes
Link *fillLst(int);
void prntLst(Link *);
void destroy(Link *);

//Prototype function you are to consider for Wednesday
Link *create(int);    //Create a Link with Data
void pshFrnt(Link *&); //Push a link to the front
void pshBack(Link *&); //Push a link to the end
Link *popFrnt(Link *&);      //Pull/pop a link from the front
Link *popBack(Link *&);      //Pull/pop a link from the back

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    
    //Declare variables
    Link *lnk1=fillLst(8);
    //Printing all the data elements in the linked list
    prntLst(lnk1);
    pshFrnt(lnk1);
    cout << endl;
    prntLst(lnk1);
    cout << endl;
    pshBack(lnk1);
    prntLst(lnk1);
    cout << endl;
    lnk1 = popFrnt(lnk1);
    prntLst(lnk1);
    cout << endl;
    lnk1 = popBack(lnk1);
    prntLst(lnk1);
    
    //Delete all the allocated memory
    destroy(lnk1);
    
    //Exit stage right
    return 0;
}
Link * create(int n)
{
    Link *newLink = new Link;
    newLink->data = n;
    newLink->lnkNext = NULL;
    
    return newLink;
}

Link *popBack(Link *&front)
{
    if(front != NULL)
    {
        Link *current = front;
        Link *prev = NULL;
        
        while(current->lnkNext != NULL)
        {
            prev = current;
            current = current->lnkNext;
        }
        
        if(prev == NULL)
            front = NULL;
        else
            prev->lnkNext = current->lnkNext;
        cout << "Popping off " << current->data << " from the back." << endl;
        delete current;
        
    }
    return front;
      
}

Link *popFrnt(Link *&front)
{
    if(front != NULL)
    {
        Link *temp = front;
        front = front->lnkNext;
        cout << "Popping off " << temp->data << " from the front." << endl; 
        delete temp;    
    }
    else
    {
        cout << "There are no links to remove." << endl;
    }
    return front;
    
}

void pshFrnt(Link *&front)
{
    int n;
    cout << "Push a value to the front: ";
    cin >> n;
    
    Link *lnk2 = create(n);
    lnk2->lnkNext = front;
    front = lnk2;
}

void pshBack(Link *&front)
{
    int n;
    cout << "Enter a value to push to the back: ";
    cin >> n;
    
    Link *newLink = create(n);
    //If list is empty, make head the new Link
    if(front == NULL)
    {
        front = newLink;
        return;
    }
    Link *last = front;
        while(last->lnkNext != NULL)
        {
            last = last->lnkNext;
        }
    last->lnkNext = newLink;
}

Link *fillLst(int n){
    //First create the front pointer/beginning pointer
    Link *front=new Link;
    front->data=1;
    front->lnkNext=NULL;
    //If n>1 then fill with the data and links to the next
    Link *temp=front;
    for(int i=2;i<=n;i++){
        Link *nxtLink=new Link;
        nxtLink->data=i;
        temp->lnkNext=nxtLink;
        temp=nxtLink;
    }
    temp->lnkNext=NULL;
    //Return the front of the list
    return front;
}

void prntLst(Link *next){
    while(next!=NULL){
        cout<<next->data<<endl;
        next=next->lnkNext;
    }
}

void destroy(Link *front){
    while(front!=NULL){
        Link *temp=front;
        front=front->lnkNext;
        delete temp;
    }
}