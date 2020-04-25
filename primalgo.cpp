#include <iostream>
#include <bits/stdc++.h> 
#include <vector>

using namespace std;

// A C++ program for Prim's Minimum  
// Spanning Tree (MST) algorithm of a given connected, undirected and 
// weighted graph 
 

// Creating shortcut for an integer pair 


	// Utility function to add an edge 
	void addEdge(vector < pair<int,int > >  myvector[],int u, int v, int w) 
	{ 
		myvector[u].push_back(make_pair(v,w)); 
		myvector[v].push_back(make_pair(u,w));
	} 
 

void printMST(int parent[],int edges)
{
	cout<<"\n"<<"Prim MST is"<<" "<<"\n";
	for(int i=1;i<edges+1;i++)
	{
		cout<<parent[i]<<"-"<<i<<"\n";
	}
}

int minkey(int key[], bool mstSet[],int V)
 {
   int min=INT_MAX;
   int size=V;
   int minindex;

   for(int i=0;i<V;i++)
   {
   	 if(mstSet[i]==false && key[i]<min)
   	 {
   	 	min=key[i];
   	 	minindex=i;
   	 }
   }

   return minindex;
 }


void PrimMST(vector <pair <int,int> > myvector[],int V,int E)
{

   int key[V];
   bool mstSet[V];
   int parent[V];
   for(int i=0;i<V;i++)
   {
   	 key[i]=INT_MAX;
   	 mstSet[i]=false;
   }

   key[0]=0; 
   parent[0]=-1;

   for(int i=0;i<V-1;i++)
   {
   	 int u= minkey(key,mstSet,V);
   	 //cout<<"baba "<< u;

   	 mstSet[u]=true;
     
     for(int j=0;j< myvector[u].size();j++)
     {
     	int v=myvector[u][j].first;
     	int w=myvector[u][j].second;
     	if(mstSet[v]==false  && w<key[v])
     	{
     		key[v]=w;
     		parent[v]=u;
     	}
     }
   }

   printMST(parent,V-1);
	
}



// Driver program to test above functions 
int main()
{
	int V = 9, E = 14;

	//Take dimension vector equivalent to total points in graph
	vector <pair <int,int> > myvector[V];

	addEdge(myvector,0, 1, 4); 
	addEdge(myvector,0, 7, 8); 
	addEdge(myvector,1, 2, 8); 
    addEdge(myvector,1, 7, 11); 
	addEdge(myvector,2, 3, 7); 
	addEdge(myvector,2, 8, 2); 
	addEdge(myvector,2, 5, 4); 
	addEdge(myvector,3, 4, 9); 
	addEdge(myvector,3, 5, 14); 
	addEdge(myvector,4, 5, 10); 
	addEdge(myvector,5, 6, 2); 
	addEdge(myvector,6, 7, 1); 
	addEdge(myvector,6, 8, 6); 
	addEdge(myvector,7, 8, 7);
    //addEdge(myvector, 3, 4);

    PrimMST(myvector,V,E);

    return 0;
}