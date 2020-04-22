// C++ program for Kruskal's algorithm to find Minimum 
// Spanning Tree of a given connected, undirected and 
// weighted graph 
#include<bits/stdc++.h> 
using namespace std; 

// Creating shortcut for an integer pair 
typedef pair<int, int> iPair; 

// Structure to represent a graph 
struct Graph 
{ 
	int V, E; 
	vector< pair<int, iPair> > edges; 

	// Constructor 
	Graph(int V, int E) 
	{ 
		this->V = V; 
		this->E = E; 
	} 

	// Utility function to add an edge 
	void addEdge(int u, int v, int w) 
	{ 
		edges.push_back({w, {u, v}}); 
	} 
 
}; 

int find(int parent[],int i)
{
    if(parent[i]==-1)
        return i;
    else
        return find(parent,parent[i]);

}

void Union(int parent[],int x,int y)
{
    int xset=find(parent,x);
    int yset=find(parent,y);
    if(xset!=yset)
    {
        parent[xset]=yset;
    }
}


void Kruskel(Graph g,int V,int E)
{
	Graph tempgraph(V,V-1);
	int weisum=0;
	int totaledges=0;
	sort(g.edges.begin(),g.edges.end());
    vector< pair<int, iPair> >::iterator i;
	/*for(i=g.edges.begin();i!=g.edges.end();i++)
	{
		cout<<i->first<<" "<<i->second.first<<"\n";
	}*/

	int parent[V];
	for(int i=0;i<V;i++)
	{
		parent[i]=-1;
	}
    vector< pair<int, iPair> >::iterator j;
	for(j=g.edges.begin();j!=g.edges.end();j++)
	{
		int weightt=j->first;
       int src=j->second.first;
       int dst=j->second.second;

       int x=find(parent,src);
       int y=find(parent,dst);

    	if(x!=y && totaledges!=V-1)
        {
          totaledges++;
          tempgraph.addEdge(src,dst,weightt);
          Union(parent,x,y);
        }

     
	}
	cout << "Edges of MST are \n";
	vector< pair<int, iPair> >::iterator k;
	for(k=tempgraph.edges.begin();k!=tempgraph.edges.end();k++)
	{
		cout<<k->first<<" "<<k->second.first<<"-"<<k->second.second<<"\n";

		weisum=weisum+k->first;

	}

	cout << "\nWeight of MST is "<<weisum;


}



// Driver program to test above functions 
int main() 
{ 
	/* Let us create above shown weighted 
	and unidrected graph */
	int V = 9, E = 14; 
	Graph g(V, E); 

	// making above shown graph 
	g.addEdge(0, 1, 4); 
	g.addEdge(0, 7, 8); 
	g.addEdge(1, 2, 8); 
	g.addEdge(1, 7, 11); 
	g.addEdge(2, 3, 7); 
	g.addEdge(2, 8, 2); 
	g.addEdge(2, 5, 4); 
	g.addEdge(3, 4, 9); 
	g.addEdge(3, 5, 14); 
	g.addEdge(4, 5, 10); 
	g.addEdge(5, 6, 2); 
	g.addEdge(6, 7, 1); 
	g.addEdge(6, 8, 6); 
	g.addEdge(7, 8, 7); 

	Kruskel(g,V,E);

	return 0; 
} 

