/** 
 * @file:   main.cpp
 * @author: Attila Koksal
 * @date: Created on June 9, 2022, 5:30 PM
 * Purpose:  Problem 1 
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <string>
#include <sstream>
#include <map>
#include <queue>
using namespace std;

int pHash(string str) {
    stringstream ss;
    for ( int i = 0; i < 3; i++ ) {
        int j = 0;
        char c = str[i];
        if ( c >= 65 && c <= 67 ) {
            j = 2;
        } else if ( c >= 68 && c <= 70 ) {
            j = 3;
        } else if ( c >= 71 && c <= 73 ) {
            j = 4;
        } else if ( c >= 74 && c <= 76 ) {
            j = 5;
        } else if ( c >= 77 && c <= 79 ) {
            j = 6;
        } else if ( c >= 80 && c <= 83 ) {
            j = 7;
        } else if ( c >= 84 && c <= 86 ) {
            j = 8;
        } else if ( c >= 85 && c <= 90 ) {
            j = 9;
        }
        ss << "" << j;
    }
    return atoi( ss.str( ).c_str( ) );
}

void p1() {
    int size = 500;
    string str = " ";
    fstream file;
    file.open( "p1.dat", ios::out );
    map<int, int> stats;
    int bitvec[size];
    for ( int i = 0; i < size; i++ ) {
        bitvec[i] = 0;
    }
    for ( int i = 0; i < size; i++ ) {
        str[0] = (char) ( rand( ) % 26 + 65 );
        str[1] = (char) ( rand( ) % 26 + 65 );
        str[2] = (char) ( rand( ) % 26 + 65 );
        int hash = pHash( str );
        file << str[0] << str[1] << str[2] << " " << hash << endl;
        bitvec[hash % size]++;
    }
    file << "collision array\n";
    for ( int i = 0; i < size; i++ ) {
        if ( stats.count( bitvec[i] ) <= 0 ) {
            stats[ bitvec[i] ] = 1;
        } else {
        stats[ bitvec[i] ]++;
        }
    file << setw( 2 ) << bitvec[i] << " ";
    if ( ( i + 1 ) % 25 == 0 ) {
        file << endl;
    }

}
int total = 0;
    for ( map<int, int>::iterator it = stats.begin( ); it != stats.end( ); it++ ) {
        if ( it->first != 0 ) {
            total += it->second;
        }
    cout << it->first << " collisions occurred #" << it->second << endl;
    file << it->first << " collisions occurred #" << it->second << endl;
    }
    cout << "Max number of collisions is: " << ( --stats.end( ) )->first << endl;
    file << "Max number of collisions is: " << ( --stats.end( ) )->first << endl;
    cout << "Total collisions: " << total << endl;
    file << "Total collisions: " << total << endl;
    float avg = (float) size / total;
    cout << "average search: " << avg << endl;
    file << "average search: " << avg << endl;
    file.close( );
}

int main() {
    srand(time(0));
    p1();
    return 0;
}