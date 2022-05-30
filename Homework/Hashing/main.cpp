/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 26, 2022, 3:45 PM
 */

#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <string>
#include <chrono>
#include <ctime>
#include <cmath>
#include <iostream>

using namespace std;
const int SIZE = 50000;
 
class Hash{
 private:
     static const int tableSize = SIZE;
     
     struct item{
         string value;
         item* next;
     };
     
     item* array3[tableSize];
 public:
     Hash();
     int hasher(string value);
     void addItem(string value);
     void hashSearch(string value);
     void printTable();
     int NumberOfItems(int index);
     
 };
 
 
 Hash::Hash(){
     for(int i = 0; i < tableSize; i++)
     {
         array3[i] = new item;
         array3[i]->value = "empty";
         array3[i]->next = NULL;
     }
 }
 
 int Hash::hasher(string value){
     int hash = 0;
     int index;
     
     for(int i = 0; i < value.length(); i++)
     {
         hash = hash + (int)value[i];
     }
     
     index = hash % SIZE;
     return index;
 }
 
 int Hash::NumberOfItems(int index){
     int count = 0;
     if(array3[index]->value == "empty")
     {
         return count;
     }
     else
     {
         count++;
         item *Ptr = array3[index];
         while(Ptr->next != NULL)
         {
             count++;
             Ptr = Ptr->next;
         }
     }
     return count;
 }
 
 void Hash::printTable(){
     int number;
     for(int i = 0; i < tableSize; i++)
     {
         number = NumberOfItems(i);
         cout << "----------------\n";
         cout << "Number of items inside Index " << i << ": " << number << endl;
         cout << array3[i]->value << endl;
         
         if(number > 1)
         {
             item *Ptr = array3[i];
             Ptr = Ptr->next;
             while(Ptr != NULL)
             {
                 cout << Ptr->value << endl;
                 Ptr = Ptr->next;
             }
             cout << "----------------\n";
         }
         
     }
 }
 void Hash::addItem(string value){
     int index = hasher(value);
     
     if(array3[index]->value == "empty")
     {
         array3[index]->value = value;
     }
     else
     {
         item* Ptr = array3[index];
         item *n = new item;
         n->value = value;
         n->next = NULL;
         
         while(Ptr ->next != NULL)
         {
             Ptr = Ptr->next;
         }
         
         Ptr->next = n;
     }
 }
 
 void Hash::hashSearch(string value){
     int index = hasher(value);
     bool foundString = false;
     
     item* Ptr = array3[index];
     while(Ptr != NULL)
     {
         if(Ptr->value == value)
         {
             foundString = true;
         }
         Ptr = Ptr->next;
     }
     if(foundString == true)
     {
         cout << "The string value: " << value << ", was found at index " << index << endl;
     }
     else
     {
          cout << "The string: " << value << ", could not be found. " << endl;
     }
 }
 
 void BinarySearch(string arr[],string value){
     int l = 0;
     int r = SIZE - 1;
     
         while(l <= r)
         {
             int mid = (l + r)/2;
             
            if(arr[mid] > value)
            {
                r = mid - 1;
            }
           else if(arr[mid] < value)
            {
                l = mid + 1;
            }
           else
            {
               cout << "The string: " << value << ", was found at index " << mid << endl;
               return;
            }
         
        }
     cout << "The string: " << value << ", could not be found. " << endl;
 }
 
void LinearSearch(string arr[], int SIZE , string value){
    for(int i = 0; i < SIZE; i++ )
    {
        if(arr[i] == value)
        {
            cout << "The string: " << value << ", was found at index " << i << endl;
            return;
        }
    }
    
    cout << "The string: " << value << ", could not be found. " << endl;
    
}
int main(int argc, char** argv) {
    srand(time(0));
    string array1[SIZE];
    string array2[SIZE];
    Hash hashObj;
    string searchword;
    
    for(int i = 0; i < SIZE; i++)
    {
        string word = "abcdefghijklmnopqrst";
        int length = 20;
        
        for(int j = 0; j < length; j++)
        {
            word[j] = 'a' + (rand()%26);
        }
        
        array1[i] = array2[i] = word;
    }
    
    for(int j = 0; j < SIZE; j++)
    {
        hashObj.addItem(array1[j]);
    }
    
    int z = sizeof(array2)/sizeof(array2[0]);
    sort(array2,array2+z);
  
    searchword = array1[rand()%SIZE];

    cout << "Performing Hash Search for a known String: " << endl;
    std::chrono::steady_clock::time_point begin3 = std::chrono::steady_clock::now();
    hashObj.hashSearch(searchword);
    std::chrono::steady_clock::time_point end3 = std::chrono::steady_clock::now();
    cout << endl << "The time taken for Hash Search with array of size " << SIZE << " in microseconds: " << std::chrono::duration_cast<std::chrono::microseconds>(end3-begin3).count() << "ms" << endl << endl;
    cout << endl;
    
    return 0;
}