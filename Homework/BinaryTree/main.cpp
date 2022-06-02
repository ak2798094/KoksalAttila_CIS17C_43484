/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Purpose: Binary Tree
 * Created on June 1, 2022, 8:58 PM
 */

#include <cstdlib>

using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;
 
    // Val is the key or the value that
    // has to be added to the data part
    Node(int val)
    {
        data = val;
 
        // Left and right child for node
        // will be initialized to null
        left = NULL;
        right = NULL;
    }
};

int main(int argc, char** argv) {

    Node* root = new Node(1);
 
    root->left = new Node(2);
    root->right = new Node(3);
 
    root->left->left = new Node(4);
    
    return 0;
}

