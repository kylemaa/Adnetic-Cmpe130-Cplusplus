#ifndef Hash_h
#define Hash_h

const int MAX_SIZE = 40;
#include <cstring>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <string>
#include <cstdio>

using namespace std;

class HashNode
{
public:
    int key;
    int v;
    int value;
    string name;
    HashNode *next;
    
    HashNode(string name, int key, int value)
    {
        this -> name = name;
        this -> key = key;
        this -> value = value;
        this -> next = NULL;
        
    }
    
};

class HashTable
{
public:
    
    HashNode **hTable;
    
    void display();
    string findMax(string);
    
    HashTable()
    //clearing the hash table
    {
        hTable = new HashNode*[MAX_SIZE];
        
        for(int i = 0; i< MAX_SIZE; i++)
            hTable[i] = NULL;
    }
    
    void insert(string name, int key, int value)
    {
        int hashKey = key;
        
        HashNode* prev = NULL;
        HashNode* in = hTable[hashKey];
        
        while(in != NULL)
        {
            prev = in;
            in = in -> next;
        }
        
        if(in == NULL)
        {
            in = new HashNode(name, key, value);
            
            if(prev == NULL)
            {
                hTable[hashKey] = in;
            }
            
            else
            {
                prev -> next = in;
                
            }
        }
        
        else
        {
            in -> value = value;
        }
    }
    
};

#endif /* Hash_h */
