#include "Hash.hpp"
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

int find_key(string k)
{
    char copy[50];
    int key;
    int sum=0;
    int length = k.length();
    
    strcpy(copy, k.c_str());
    
    
    for(int i =0; i<length; i++)
    {
        sum += int(copy[i]);
        
    }
    
    key = sum / 100;
    
    return key;
}

void HashTable:: display()
{
    HashNode *myNode;
    
    for(int i =0; i< 12; i++)
    {
        myNode = hTable[i];
        
        if(hTable[i] != NULL)
        {
            cout<<"Data at index "<< i<<" "<<endl;
        }
        while (myNode != NULL)
        {
            cout<<myNode ->name<<" ";
            cout<<myNode ->value<<endl;
            
            myNode = myNode ->next;
        }
        cout<<endl;
    }
    
    
}

string HashTable:: findMax(string categoryIn)
{
    HashNode *list = NULL;
    HashNode *ptr = NULL;
    int m;
    string max_name;
    
    int key = find_key(categoryIn);
    
    
    list = hTable[key];
    
    m = list->value;
    max_name = list->name;
    
    if(list!=NULL)
    {
        if(list->next != NULL)
            
        {
            
            ptr = list ->next;
            
            while(ptr->next != NULL)
            {
                
                if(ptr->value > m)
                {
                    m = ptr->value;
                    max_name = ptr -> name;
                }
                
                ptr = ptr->next;
            }
        }
    }
    return max_name;
}
