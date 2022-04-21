/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Purpose:  Find Algorithm
 */

//System Libraries

#include <bits/stdc++.h>

using namespace std;

int getMissingNo(int *,int);

int main(int argc, char** argv) {
    
    int arr[] = { 1, 2, 4, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int miss = getMissingNo(arr, n);
    cout << miss;
    
    return 0;
}
int getMissingNo(int a[], int n)
{
    int total = (n + 1) * (n + 2) / 2;
    for (int i = 0; i < n; i++)
        total -= a[i];
    return total;
}