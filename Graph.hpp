#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <list>
#include <stack>
#include <limits.h>
#include <ctime>
#include <cmath>
#include <string>
#include <cstdlib>
#include <cstdio>

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
using namespace std;

class AdjListNode
{
    int v;
    int weight;
public:
    AdjListNode(int _v, int _w)  { v = _v;  weight = _w;}
    int getV()       {  return v;  }
    int getWeight()  {  return weight; }
    
};

// Class to represent a graph using adjacency list representation
class Graph
{   int number,index;
    int V;    // No. of vertices'
    
    // Pointer to an array containing adjacency lists
    list<AdjListNode> *adj;
    
    // A function used by longestPath
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);   // Constructor
    int count = 0;
    
    // function to add an edge to graph
    void addEdge(int u, int v, int weight);
    
    // Finds longest distances from given source vertex
    void longestPath(int s);
    int getmax();
    int getindex();
    };



#endif /* Graph_hpp */

