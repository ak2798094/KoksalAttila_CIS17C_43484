/** 
 * @file:   main.cpp
 * @author: Attila Koksal
 * @date: Created on June 10, 2022, 1:45 PM
 * Purpose:  Problem 4 
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
using namespace std;

void sorting();
short* fill(int);
short* copy(short*, int);
void mergeSort(short*,int,long long&);
void pElementMergeSort(short*, short*, int, int, long long&);
void mergeComparisonOfElements(short*, short*, int, int, int, long long&);
void swap(short*, short*, long long&);
void selectionSort(short[],int,long long&);

int main(int argc, char** argv) {
    sorting();
    return 0;
}

void sorting() {
    int size = 100000;
    short *master = fill( size );
    short *array = copy(master, size);
    long s, e;
    long long count = 0;

    s = time(0);
    mergeSort(array, size, count);
    e = time(0);
    cout << "The merge sort operations: " << count << endl;
    cout << "The merge sort time: " << (e-s) << endl;
    delete [] array;
    array = copy(master, size);

    count = 0;
    s = time(0);
    selectionSort(array, size, count);
    e = time(0);
    cout << "The selection sort operations: " << count << endl;
    cout << "The selection sort time: " << (e-s) << endl;

    delete [] array;
    delete [] master;
}

//merge sort
void mergeSort(short *integer, int size, long long &count) {
    short *temp = new short[ size ];
    count++;
    pElementMergeSort(integer, temp, 0, size - 1, count);
}

//p element merge sort
void pElementMergeSort(short *integer, short *temp, int left, int right, long long &count) {
    count++;
    if(left < right) {
        int center = (left + right) / 2;
        count++;
        pElementMergeSort(integer, temp, left, center, count);
        pElementMergeSort(integer, temp, center + 1, right, count);
        mergeComparisonOfElements(integer, temp, left, center, right, count);
    }
}

//comparison
void mergeComparisonOfElements(short *integer, short *temp, int left, int center, int right, long long &count) {
    int leftBegin = left;
    int leftEnd = center;
    int rightBegin = center + 1;
    int rightEnd = right;
    int i = 0;
    count+=5;

    while ((leftBegin <= leftEnd) && (rightBegin <= rightEnd)) {
        count+=3;
        if(integer[leftBegin] <= integer[rightBegin]) {
            temp[i] = integer[leftBegin];
            leftBegin++;
            count+=2;
        } else{
            temp[i] = integer[rightBegin];
            rightBegin++;
            count+=2;
        }
        i++;
        count++;
    }

    while (leftBegin <= leftEnd) {
        temp[i] = integer[leftBegin];
        i++;
        leftBegin++;
        count+=4;
    }

    while (rightBegin <= rightEnd) {
        temp[i] = integer[rightBegin];
        i++;
        rightBegin++;
        count+=4;
    }

    count++;
    for (int j = left; j <= rightEnd; j++) {
        integer[j] = temp[j - left];
        count+=3;
    }
}


short* fill(int size){
    short *t = new short[size];
    for (int i = 0; i < size; i++){
        t[i] = rand() % size;
    }
    return t;
}

short* copy(short *array, int size) {
    short *temp = new short[size];
    for (int i = 0; i < size; i++){
        temp[i] = array[i];
    }
    return temp;
}

//swap the element
void swap(short *xPoint, short *yPoint, long long& count){
    int temp = *xPoint;
    *xPoint = *yPoint;
    *yPoint = temp;
    count+=3;
}

//selection sort
void selectionSort(short array[], int n, long long& count){
    int i, j, minimum_index;
    count++;
    for (i = 0; i < n-1; i++)
    {
        minimum_index = i;
        count++;
        for (j = i+1; j < n; j++)
            if (array[j] < array[minimum_index])
                minimum_index = j;
        count += 7;
        swap(&array[minimum_index], &array[i], count);
    }
}