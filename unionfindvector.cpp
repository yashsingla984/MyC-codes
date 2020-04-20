#include <iostream>
#include <bits/stdc++.h> 
#include <vector>

using namespace std;





void addEdge(vector<int> myvector[],int u,int v)
{
	myvector[u].push_back(v);  //add v to u list
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

int isCycle(vector<int> myvector[],int V,int E)
{
	int size=V;
	int parent[size];

	for(int i=0;i<size;i++)
    {
        parent[i]=-1;
        //cout<<parent[i];
    }

    for(int i=0;i<V;i++)
    {
    	for(int j=0;j<myvector[i].size();j++)
    	{
    		int src=i;
    		int dst=myvector[i][j];

    		int x=find(parent,src);
    		int y=find(parent,dst);

    		if(x==y)
    			return 1;
    		else
    			Union(parent,x,y);
    	}
    }

    return 0;


}


int main()
{
	int V=5;
    int E=4;

	//Take dimension vector equivalent to total points in graph
	vector<int> myvector[V];

	addEdge(myvector, 0, 1); 
    addEdge(myvector, 1, 3); 
    addEdge(myvector, 0, 2);
    addEdge(myvector, 1, 4);
    //addEdge(myvector, 3, 4);

    if(isCycle(myvector,V,E))
    	cout<<"graph contains cycle";  
    else
        cout<<"graph doesn't contain cycle";
}