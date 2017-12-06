//
//  Graph.cpp
//  Adnetic
//
//  Created by Kyle Ma on 11/30/17.
//  Copyright © 2017 Kyle Ma. All rights reserved.
//  Reference http://www.geeksforgeeks.org/topological-sorting/
//  Reference http://www.geeksforgeeks.org/find-longest-path-directed-acyclic-graph/

#include "Graph.hpp"
#define NINF INT_MIN
Graph::Graph(int V) // Constructor
{
    this->V = V;
    adj = new list<AdjListNode>[V];
}

void Graph::addEdge(int u, int v, int weight)
{
    AdjListNode node(v, weight);
    adj[u].push_back(node);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    // Mark the current node as visited
    visited[v] = true;
    
    // Recur for all the vertices adjacent to this vertex
    list<AdjListNode>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        AdjListNode node = *i;
        if (!visited[node.getV()])
            topologicalSortUtil(node.getV(), visited, Stack);
    }
    
    // Push current vertex to stack which stores topological sort
    Stack.push(v);
}

// The function to find longest distances from a given vertex. It uses
// recursive topologicalSortUtil() to get topological sorting.
void Graph::longestPath(int s)
{
    stack<int> Stack;
    int dist[V];
    int i,m,max = 0;
    
    
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    
    // Call the recursive helper function to store Topological Sort
    // starting from all vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);
    
    // Initialize distances to all vertices as infinite and distance
    // to source as 0
    for (int i = 0; i < V; i++)
        dist[i] = NINF;
    dist[s] = 0;
    
    // Process vertices in topological order
    while (Stack.empty() == false)
    {
        // Get the next vertex from topological order
        int u = Stack.top();
        Stack.pop();
        
        // Update distances of all adjacent vertices
        list<AdjListNode>::iterator i;
        if (dist[u] != NINF)
        {
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
                if (dist[i->getV()] < dist[u] + i->getWeight())
                    dist[i->getV()] = dist[u] + i->getWeight();
            
        }
        
        
        
    }
    // Print the calculated longest distances
    
    for (int i = 0; i < V; i++)
        if(dist[i] == NINF) cout << "INF ";
        else cout << dist[i] << " ";
    max = dist[0];
    
    for ( i = 0; i < V; i++)
    {
        
        
        if(dist[i]>max)
        {
            max = dist[i];
            m=i;
        }
    }
    index= m;
    number= dist[m];
    cout<<"Longest Path has the distance of "<< number;
    
}
int Graph::getmax(){
    return number;
}
int Graph::getindex(){
    return index;
}

