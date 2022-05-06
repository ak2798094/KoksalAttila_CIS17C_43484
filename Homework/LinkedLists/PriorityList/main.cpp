/* 
 * File:   main.cpp
 * Author: Attila Koksal
 *
 * Created on May 3, 2022, 4:50 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

class DList
{
private:
    struct Node{
        int data;
        Node *next;
        Node *prev;
    };
    
    Node *begin, *end;
public:
    
    DList()
    {
        begin = NULL;
        end = NULL;
    }
    
    void destroy()
    {
        Node *temp = new Node;
        while(begin!=NULL)
       {
           temp = begin;
           begin=begin->next;
           delete temp;
        }
        end = NULL;
        cout << "\n All nodes have been removed" << endl;
        
    }
    
    void forwardDisplay()
    {
        if(begin == NULL)
        {
            cout << "No elements to traverse" << endl;
        }
        else
        {
            Node *ptr = begin;
            cout << "\n Forward List : ";
            while(ptr != NULL)
            {
                cout << " " << ptr->data;
                ptr = ptr->next;
            }
        }
    }
    
    void backwardsDisplay()
    {
        if(end == NULL)
        {
         cout << "No elements to traverse" << endl;   
        }
        else
        {
            Node *ptr = end;
            cout << "\n Backwards List : ";
            while(ptr != NULL)
            {
                cout << " " << ptr->data;
                ptr = ptr->prev;
            }
        }
    }
    
    void pop_front()
    {
        if(begin != NULL)
        {
            Node *temp = begin;
            begin = begin->next;
            
            if(begin)
            {
                begin->prev = NULL;
            }
            else
            {
                end = NULL;
            }
            delete temp;
        }
        else
        {
            cout << "There are no nodes to delete" << endl;
        }
    }
    
   void pop_back()
    {
      if(end != NULL)
       {
          Node *temp = end;
          end = end->prev;
          
          if(end)
          {
              end->next = NULL;
          }
          else
          {
              begin = NULL;
          }
          delete temp;
       }
      else
      {
          cout << "There are no nodes to delete" << endl;
      }
    }
    
    
    void pushFront(int val)
    {
        Node *temp = new Node;
        temp->prev = NULL;
        temp->data = val;
        if(begin == NULL)
        {
            temp->next = NULL;
            end = temp;
        }
        else
        {
            temp->next = begin;
            begin->prev = temp;
        }
        begin = temp;
        this->Sort();
    }
    
    
    void pushBack(int val)
    {
        Node *temp = new Node;
        temp->next = NULL;
        temp->data = val;
        if(end == NULL)
        {
            temp->prev = NULL;
            begin = end = temp;
        }
        else
        {
            temp->prev = end;
            end->next = temp;
        }
        end = temp;
        this->Sort();
    }
    
    void Sort()
    {
        Node *i = begin, *j = NULL;
        int val;
        
        while(i != NULL)
        {
            j = i->next;
            while(j != NULL)
            {
                if(i->data < j->data)
                {
                    val = i->data;
                    i->data = j->data;
                    j->data = val;
                }
                j=j->next;
            }
            i=i->next;
        }
    }
    
};

int main(int argc, char** argv) 
{
    //In this example, the list automatically places the highest element at the front
    // no matter the order in which they were placed so we don't need to sort.
    DList list;
    list.pushBack(5);
    list.pushBack(6);
    list.pushBack(13);
    list.pushBack(2);
    list.pushFront(1);
    list.forwardDisplay();
    list.pop_back();
    list.pop_back();
    list.forwardDisplay();
    list.pushBack(20);
    list.pushFront(-2);
    list.pop_front();
    list.forwardDisplay();
    list.backwardsDisplay();
    
    list.destroy();

    return 0;
}