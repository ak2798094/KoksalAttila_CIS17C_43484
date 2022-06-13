/** 
 * @file:   main.cpp
 * @author: Attila Koksal
 * @date: Created on June 11, 2022, 10:45 AM
 * Purpose:  Problem 6
 */

#include <cstdlib>
#include <iostream>

using namespace std;
 
const int sizeVertice = 7;     //Stores constant max number of vertices
const int maxValInt = 2147483647;   //Constant max cap for Integer data type
  
void prim(int[][sizeVertice]);
int calMinDist(int[], bool[]);
int showMinSpanTree(int[], int, int [][sizeVertice]);
int shortestDistanceFinder(int [][sizeVertice], int, int);
int minVal(int[], bool []);

int main(){
    
        enum destination {SFO, ORD, JFK, DFW, MIA, LAX, BOS};
    
    //graph input
                     
   int graph[sizeVertice][sizeVertice] = {
        /*SFO   ORD   JFK    DFW  MIA   LAX   BOS*/ 
        {0   , 1847, 0   , 1465, 0   , 338 , 2703},  //SFO
        {1847, 0   , 743 , 803 , 0   , 0   , 868 },  //ORD
        {0   , 743 , 0   , 0   , 1093, 0   , 189 },  //JFK
        {1465, 803 , 0   , 0   , 1124, 1234, 0   },  //DFW
        {0   , 0   , 1093, 1124, 0   , 2341, 1257},  //MIA
        {338 , 0   , 0   , 1234, 2341   , 0   , 0},  //LAX
        {2703, 868 , 189   , 0 , 1257, 0   , 0   }   //BOS
           
    };
    

    //Displays shortest distance from ORD to LAX
    cout << endl << "Shortest Distance from ORD to LAX = "
         << shortestDistanceFinder(graph, ORD, LAX) << endl;
 
    cout << endl;

    cout << endl << "Shortest Distance from JFK to SFO = "
         << shortestDistanceFinder(graph, JFK, SFO) << endl;
 
    cout << endl;
    
     
    //Displays minimum spanning tree with weighted value
    cout << endl << "Minimum Spanning Tree:" << endl << endl;
    prim(graph);
    
}

//Finds vertex with min. distance
int calMinDist(int arrDist[], bool isShortest[]){
    
   int min = maxValInt, minIndx;
  
   for(int i = 0; i < sizeVertice; i++)
        if(isShortest[i] == false && arrDist[i] <= min)
         min = arrDist[i], minIndx = i;
  
   return minIndx;
}

  
int shortestDistanceFinder(int graph[sizeVertice][sizeVertice], int start, int end){
     int arrDist[sizeVertice];
  
     bool isShortest[sizeVertice];
  
    for (int i = 0; i < sizeVertice; i++)
        arrDist[i] = maxValInt, isShortest[i] = false;
  
    //assigning distance of vertex as itself
    arrDist[start] = 0;
  
    //searches for shortest distance
    for(int i = 0; i < sizeVertice - 1; i++){
        int newMinDist = calMinDist(arrDist, isShortest);
  
        isShortest[newMinDist] = true;
  
        for (int cVertice = 0; cVertice < sizeVertice; cVertice++)
            if(!isShortest[cVertice] && graph[newMinDist][cVertice] && arrDist[newMinDist] 
               != maxValInt && arrDist[newMinDist]+graph[newMinDist][cVertice] 
                    < arrDist[cVertice])
                arrDist[cVertice] = arrDist[newMinDist] + graph[newMinDist][cVertice];
     }
  
     //returns the shortest distance between 2 vertices
     return arrDist[end];
}
  
//Selects new vertex
int minVal(int arrVal[], bool vertStat[]){
   // Initialize min value
   int min = maxValInt, min_index;
 
   for (int v = 0; v < sizeVertice; v++)
     if (vertStat[v] == false && arrVal[v] < min)
         min = arrVal[v], min_index = v;
 
   return min_index;
}
 
//Displays results or minimum spanning tree
int showMinSpanTree(int parent[], int n, int graph[sizeVertice][sizeVertice]){
    const string airportNames[sizeVertice] = {"SFO", "ORD", "JFK", "DFW", 
                                          "MIA", "LAX", "BOS"};
    cout << "   Edge    \tWeight" << endl;
    int weighted = 0;
    for (int i = 1; i < sizeVertice; i++){
        int temp = graph[i][parent[i]];
        weighted += temp;
        cout << airportNames[parent[i]] << " - " << airportNames[i] << " -->\t"
                 << temp << endl;
    }
    cout << endl << "Weighted = " << weighted << endl;
    
    return 0;
}
 
//Using prim to find the minimum spanning tree of graph
void prim(int graph[sizeVertice][sizeVertice]){
    int parent[sizeVertice];
    int val[sizeVertice];
    bool vertStat[sizeVertice];

    for(int i = 0; i < sizeVertice; i++)
        val[i] = maxValInt, vertStat[i] = false;

    val[0] = 0;
    parent[0]--; //The root of min. spanning tree

    for(int count = 0; count < sizeVertice-1; count++){
        int newMin = minVal(val, vertStat);
 
        //set used vertices
        vertStat[newMin] = true;
 
        for (int cVertice = 0; cVertice < sizeVertice; cVertice++)
            if (graph[newMin][cVertice] && vertStat[cVertice] == false && 
                    graph[newMin][cVertice] <  val[cVertice])
                parent[cVertice] = newMin, val[cVertice] = graph[newMin][cVertice];
     }
 
     //Shows minimum spanning tree
     showMinSpanTree(parent, sizeVertice, graph);
}