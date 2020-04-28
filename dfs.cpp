#include <iostream>
#include <bits/stdc++.h> 
#include <vector>

using namespace std;


void DFSUtil(bool visited[],vector<int> myvector[],int position)
{
	int s=position;
	cout<<s<<"\n";
	visited[s]=true;


	for(int i=0;i<myvector[s].size();i++)
	{
		position=myvector[s][i];
		if(visited[position]!=true)
		{
		 DFSUtil(visited,myvector,position);
		}
	}

}

void DFS(int s, vector<int> myvector[],int V)
{
	bool visited[V];

	for(int i=0;i<V;i++)
	{
		visited[i]=false;
	}

	cout<<s<<"\n";
	visited[s]=true;

	for(int i=0;i<myvector[s].size();i++)
	{
		int position=myvector[s][i];
		if(visited[position]!=true)
		{
		 DFSUtil(visited,myvector,position);
		}
	}
}


void addEdge(vector<int> myvector[],int u,int v)
{
	myvector[u].push_back(v);  //add v to u list
}



int main()
{
	int V=5;
	//Take dimension vector equivalent to total points in graph
	vector<int> myvector[V];

	addEdge(myvector, 0, 1); 
    addEdge(myvector, 0, 2); 
    addEdge(myvector, 1, 2); 
    addEdge(myvector, 2, 0); 
    addEdge(myvector, 2, 3); 
    addEdge(myvector, 3, 3);  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 

         //Now we will make BFS
    DFS(2,myvector,V);


	return 0;
	
}