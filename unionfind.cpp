#include <iostream>
#include <bits/stdc++.h> 
#include <vector>

using namespace std;

class Edge
{
public:
    int src;
    int dst;
};

class Graph
{
public:
    int V,E;

    Edge *edge;
};

Graph *createGraph(int V,int E)
{
    Graph *graph=new Graph();
    graph->V=V;
    graph->E=E;

    graph->edge=new Edge[(graph->E*sizeof(Edge))];
}

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

int isCycle(Graph *graphh)
{

    //cout<<graphh->V<<"\n";
    int size=graphh->V;
    cout<<size<<"\n";
    int parent[size];

    //cout<<sizeof(*parent)<<"\n";

    //memset(parent,-1,3);

    for(int i=0;i<size;i++)
    {
        parent[i]=-1;
        //cout<<parent[i];
    }

    for(int i=0;i<size;i++)
    {
        int x=find(parent,graphh->edge[i].src);
        int y=find(parent,graphh->edge[i].dst);

        if(x==y)
            return 1;
        
        else
            Union(parent,x,y);
    }

    return 0;
}



int main()
{
    int V=3;
    int E=3;
    Graph *graphhh=createGraph(V,E);

    graphhh->edge[0].src=0;
    graphhh->edge[0].dst=1;

    graphhh->edge[1].src=1;
    graphhh->edge[1].dst=2;

    graphhh->edge[2].src=0;
    graphhh->edge[2].dst=2;


    if(isCycle(graphhh))
        cout<<"graph contains cycle";  
    else
        cout<<"graph doesn't contain cycle";


	return 0;
	
}