#include <iostream>
#include <bits/stdc++.h> 
#include <vector>

using namespace std;

//A C++ program for Dijkstra's single source shortest path algorithm. 
// The program is for adjacency matrix representation of the graph 

// Creating shortcut for an integer pair 


	// Utility function to add an edge 
	void addEdge(vector < pair<int,int > >  myvector[],int u, int v, int w) 
	{ 
		myvector[u].push_back(make_pair(v,w)); 
		myvector[v].push_back(make_pair(u,w));
	} 
 

void printDijsktra(int dist[],int edges)
{
	cout<<"\n"<<"Vetex"<<"                  "<<  "Distance from source"<<"\n";
	for(int i=0;i<edges+1;i++)
	{
		cout<<i<<"                        "<<dist[i]<<"\n";
	}
}

int minkey(int dist[], bool sptSet[],int V)
 {
   int min=INT_MAX;
   int size=V;
   int minindex;

   for(int i=0;i<V;i++)
   {
   	 if(sptSet[i]==false && dist[i]<min)
   	 {
   	 	min=dist[i];
   	 	minindex=i;
   	 }
   }

   return minindex;
 }


void Dijsktra(vector <pair <int,int> > myvector[],int V,int E,int src)
{

   int dist[V];
   bool sptSet[V];
   //int parent[V];
   for(int i=0;i<V;i++)
   {
   	 dist[i]=INT_MAX;
   	 sptSet[i]=false;
     //parent[i]=-1;
   }

   dist[src]=0; 

   for(int i=0;i<V-1;i++)
   {
   	 int u= minkey(dist,sptSet,V);
   	 //cout<<"baba "<< u;

   	 sptSet[u]=true;
     
     for(int j=0;j< myvector[u].size();j++)
     {
     	int v=myvector[u][j].first;
     	int w=myvector[u][j].second;

      int distance=w+dist[u];

      if(sptSet[v]==false && distance<dist[v])
      {
        dist[v]=distance;
        //parent[v]=u;
      }
     }
   }

   printDijsktra(dist,V-1);
	
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
  int source=0;
  Dijsktra(myvector,V,E,source);

    return 0;
}