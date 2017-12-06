// A C++ program to find single source longest distances in a DAG
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
#include "Hash.hpp"
#include "Graph.hpp"


#define NINF INT_MIN

using namespace std;

void shuffle(int *arr, size_t n)
{
    if (n > 1)
    {
        size_t i;
        srand( static_cast<unsigned int>(time(NULL)));
        for (i = 0; i < n - 1; i++)
        {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = arr[j];
            arr[j] = arr[i];
            arr[i] = t;
        }
    }
}

int ShuffleDAG(string array){
    int i=0;
    int count;
    int arr[6];
    for (i=0; i<6; i++){
        arr[i] = i;
    }
    
    shuffle(arr, 6);
    
    if (strcmp(array.c_str(),"StartingPoint")==0)
        count= arr[0];
    else if(strcmp(array.c_str(),"Snapchat")==0)
        count=arr[1];
    else if(strcmp(array.c_str(),"Twitter")==0)
        count=arr[2];
    else if(strcmp(array.c_str(),"Instagram")==0)
        count=arr[3];
    else if(strcmp(array.c_str(),"WhatsApp")==0)
        count=arr[4];
    else count=arr[5];
    
    return count;
}

// Driver program to test above functions
int main()
{
    // Create a graph given in the above diagram.  Here vertex numbers are
    // 0, 1, 2, 3, 4, 5 with following mappings:
    
    int webweight[50], webweight2[50], sum[50], key[50], val[50];
    int count_web[10], count_adj[10],count_web2[10], count_adj2[10], length,v,max1, max2, maxV1,maxV2;
    string webname[50],webname2[50], adjwebname[50],adjwebname2[50], nameOfSite[50], category1[15];
    string value, maxAd, categ, data;
    char category[15];
    
    HashTable hash;
    ifstream ifs,ifd, inFile;
    
    inFile.open("traffic.txt");
    
    while(inFile.good())
    {
        for(int i = 0; i< 15; i++)
        {
            getline(inFile, nameOfSite[i], ',');
            getline(inFile, category1[i], ',');
            getline(inFile, value, '\n');
            
            
            istringstream iss(value);
            
            while(iss >> v)
            {
                val[i] = v;
            }
        }
    }
    
    //converting the categories to ascii values to find the key value on hash table
    for(int a = 0; a < 13 ; a++)
    {
        strcpy(category, category1[a].c_str());
        length =(int) category1[a].length();
        
        for(int i =0; i< length; i++)
        {
            sum[a] += int(category[i]);
            category[i] = 0;
        }
        
        key[a] = sum[a] / 100;
        
        hash.insert(nameOfSite[a], key[a], val[a]);
    }
    
    
    inFile.close();
    ifs.open("adsAPISM.dat");
    
    if(ifs.fail())
    {
        cout << "Error! File not found!" << endl;
        exit(1);
    }
    for(int i=0; i<1; i++)
    {
        getline(ifs, categ);
    }
    
    for(int i = 0; i<11; i++)
    {
        getline(ifs, webname[i], ',');
        getline(ifs, adjwebname[i], ',');
        getline(ifs, data);
        data = data.substr(0, data.find(','));
        if(isdigit(data[0])){
            istringstream iss(data);
            int weight;
            while(iss >> weight){
                webweight[i]=weight;}
        }
    }
    
    Graph g(6);
    cout<<"Social Media test case 1:"<<endl;
    cout<<"Vertex"<<"\t"<<"AdjacentVertex"<<"\t"<<"Weight"<<endl;
    for(int i = 0; i< 10; i++)
    {
        count_web[i] = ShuffleDAG(webname[i]);
        count_adj[i] = ShuffleDAG(adjwebname[i]);
        g.addEdge(count_web[i], count_adj[i], webweight[i]);
        cout<<count_web[i]<<"\t\t\t"<<count_adj[i]<<"\t\t\t"<<webweight[i]<<endl;
    }
    int s=0;
    g.longestPath(s);
    max1= g.getmax();
    maxV1=g.getindex();
   
    ifd.open("adsAPISM2.dat");
    if(ifd.fail()){
        cout << "Error! File not found!" << endl;
        exit(1);
    }
    for(int i=0; i<1; i++){
        getline(ifd, categ);
    }
    while(!ifd.eof()){
        
        for(int i = 0; i< 15; i++)
        {
            getline(ifd, webname2[i], ',');
            getline(ifd, adjwebname2[i], ',');
            getline(ifd, data);
            data = data.substr(0, data.find(','));
            if(isdigit(data[0])){
                istringstream iss(data);
                int weight;
                while(iss >> weight){
                    webweight2[i]=weight;}
            }
        }
        
        Graph g(6);
        cout<<endl<<"Social Media test case 2:"<<endl;
        cout<<"Vertex"<<"\t"<<"Adjacent vertex"<<"\t"<<"Weight"<<endl;
        for(int i = 0; i< 11; i++)
        {
            count_web2[i]= ShuffleDAG(webname2[i]);
            count_adj2[i]= ShuffleDAG(adjwebname2[i]);
            g.addEdge(count_web2[i], count_adj2[i],webweight2[i]);
            cout<<count_web2[i]<<"\t\t\t"<<count_adj2[i]<<"\t\t\t"<<webweight2[i]<<endl;

        }
        g.longestPath(s);
        max2= g.getmax();
        maxV2= g.getindex();
        //Assign most valuable ads to file that has longer distance
        maxAd = hash.findMax(categ);
        cout<<endl<<"Ad "<<maxAd<<" will be displayed on ";
        
        if(max1 > max2)
        {
            for(int i = 0; i<11; i++)
            {
                if(count_web[i] == maxV1)
                {
                    cout<<webname[i];
                    break;
                }
                else if(count_adj[i] == maxV1)
                {
                    cout<<adjwebname[i];
                    break;
                }
            }
            break;
        }
        else if(max2>max1)
        {
            for(int i = 0; i<11; i++)
            {
                if(count_web2[i] == maxV2)
                {
                    cout<<webname2[i];
                    break;
                }
                else if(count_adj2[i] == maxV2)
                {
                    cout<<adjwebname2[i];
                    break;
                }
            }
            
            
        }
    }
}
