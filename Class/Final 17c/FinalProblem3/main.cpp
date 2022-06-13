/** 
 * @file:   main.cpp
 * @author: Attila Koksal
 * @date: Created on June 10, 2022, 9:30 AM
 * Purpose:  Problem 3 
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

struct Clerk {
    bool busy;
    int startTime;
    int served;
};

void p3( ) {
    queue<int> customers;
    vector< Clerk > clerks;
    for ( int i = 0; i < 3; i++ ) {
        Clerk clerk;
        clerk.busy = false;
        clerk.startTime = 0;
        clerk.served = 0;
        clerks.push_back( clerk );
    }

    int wait = 0;
    bool waiting = true;
    int runTime = 60 * 60;
    int clerktimes[] = {60, 120, 80};
    int totalCust = 0;
    cout << "how many hours do you want to run: ";
    cin >> runTime;
    runTime*= 60*60;


    for ( int sec = 0; sec <= runTime; sec += 5 ) {
        bool free = false;
        for ( int i = 0; i < clerks.size( ); i++ ) {
            int delta = ( i > 2 ? 60 : clerktimes[i] );
            if ( clerks[i].busy ) {
                if ( clerks[i].startTime + delta == sec ) {
                    clerks[i].busy = false;
                    clerks[i].startTime = 0;
                    clerks[i].served++;
                    free = true;
                }
            }
        }

        if ( sec % 20 == 0 ) {
            customers.push( 1 );
            totalCust++;
        }

        waiting = true;
        if ( customers.size( ) > 0 ) {
            for ( int i = 0; i < clerks.size( ); i++ ) {
                if ( !( clerks[i].busy ) && customers.size( ) > 0 ) { //have to recheck size so dont add same guy to 3 tellers
                    waiting = false;
                    clerks[i].busy = true;
                    clerks[i].startTime = sec;
                    customers.pop( );
                }
            }
        wait += ( waiting ? 5 * customers.size( ) : 0 );
        }

        if( sec % 10 == 0 && false ){
            for ( int i = 0; i < clerks.size( ); ++i ) {
                cout << setw(6) << sec << setw( 3 ) << i+1 << setw( 3 ) << ( clerks[i].busy ? "T" : "F" ) << endl;
            }
        }

        if ( customers.size( ) > 5 && !free ) {
            Clerk clerk;
            clerk.busy = false;
            clerk.startTime = 0;
            clerk.served = 0;
            clerks.push_back( clerk );
        }

        if( customers.size() == 0 && clerks.size() > 3 ){
            clerks.pop_back();
        }

    }

    cout << "The number of customers is " << totalCust << endl;
    for( int i = 0; i < clerks.size(); i++ ){
        cout << "Clerk " << i + 1 << " served " << clerks[i].served << endl;
    }
    cout << "The average wait is " << ( wait / 60.0f ) / totalCust<< " minutes." << endl;
}



int main() {
    srand( time( 0 ) );
    p3();
    return 0;
}