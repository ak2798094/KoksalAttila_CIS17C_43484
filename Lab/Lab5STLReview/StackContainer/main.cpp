/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Purpose:  Stack Container
 */

//System Libraries
#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char** argv) {
    stack<int> stack;
    stack.push(21);
    stack.push(22);
    stack.push(24);
    stack.push(25);
     
         stack.pop();
    stack.pop();
 
    while (!stack.empty()) {
        cout << ' ' << stack.top();
        stack.pop();
    }
    
    return 0;
}