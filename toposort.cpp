#include <iostream>
#include <bits/stdc++.h> 
#include <vector>

using namespace std;

stack<int> topoutil(stack<int> tempstack,stack<int>finalstack,bool visited[],vector<int> myvector[],int position)
{
	int s=position;
	for(int j=0;j<myvector[s].size();j++)
	{
		position=myvector[s][j];
		if(visited[position]==false)
		{
			tempstack.push(position);
			visited[position]=true;
			if(myvector[position].size()==0)
			{
				finalstack.push(tempstack.top());
				cout<<"My name is khan in if"<<tempstack.top()<<"\n";
				tempstack.pop();
			}
			else
			{
              finalstack=topoutil(tempstack,finalstack,visited,myvector,position);
              cout<<"My name is khan in else"<<tempstack.top()<<"\n";
              finalstack.push(tempstack.top());
              tempstack.pop();
			}
		}
	}
	return finalstack;

}


void TopoSort(vector<int> myvector[],int V)
{

	bool visited[V];
	for(int i=0;i<V;i++)
	{
		visited[i]=false;
	}
	stack<int> tempstack;
	stack<int>finalstack;

	for(int i=0;i<V;i++)
	{
	  int position=i;
      if(visited[position]==false)
      {
      	tempstack.push(position);
      	visited[position]=true;
      	if(myvector[position].size()==0)
      	{
      		finalstack.push(tempstack.top());
      		cout<<"My name is khan in if"<<tempstack.top()<<"\n";
      		tempstack.pop();
      	}
      	else
      	{
          finalstack=topoutil(tempstack,finalstack,visited,myvector,position);
          cout<<"My name is khan in else"<<tempstack.top()<<"\n";
          finalstack.push(tempstack.top());
          tempstack.pop();

      	}
      }
	}

	cout<<finalstack.size()<<"\n";

	while(!finalstack.empty())
	{
		cout<<"\t"<<finalstack.top();
		finalstack.pop();
	}
}

void addEdge(vector<int> myvector[],int u,int v)
{
	myvector[u].push_back(v);  //add v to u list
}



int main()
{
	int V=6;
	//Take dimension vector equivalent to total points in graph
	vector<int> myvector[V];

	addEdge(myvector, 5, 2); 
    addEdge(myvector, 5, 0); 
    addEdge(myvector, 4, 0); 
    addEdge(myvector, 4, 1); 
    addEdge(myvector, 2, 3); 
    addEdge(myvector, 3, 1);  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 

         //Now we will make BFS
    TopoSort(myvector,V);


	return 0;
	
}