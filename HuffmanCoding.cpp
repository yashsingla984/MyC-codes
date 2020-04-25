#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

class Node
{
    public:
        char character;
    	int freq;
    	Node *left;
    	Node *right;
    	
	Node()
	{}

	Node(const Node &a)
	{
		this->character = a.character;
		this->freq = a.freq;
		this->left= a.left;
		this->right=a.right;
	}

};


Node *newNode(char character,int freq)
{
	Node *node=new Node();
	node->character=character;
	node->freq=freq;
	node->left=NULL;
	node->right=NULL;
	return node;


}

void printarr(int arrrr[],int top,Node *weHuffNode)
{

	cout<<weHuffNode->character<<"\t";
	for(int i=0;i<top;i++)
	{
		cout<<arrrr[i];
	}
	cout<<"\n";
}


void Printcodes(Node * weHuffNode,int arrrr[],int top)
{
	if(weHuffNode->left)
	{
		arrrr[top]=0;
		Printcodes(weHuffNode->left,arrrr,top+1);
	}

	if(weHuffNode->right)
	{
		arrrr[top]=1;
		Printcodes(weHuffNode->right,arrrr,top+1);
	}

	if((weHuffNode->left)==NULL &&(weHuffNode->right)==NULL)
	{
		printarr(arrrr,top,weHuffNode);
	}
}







bool comp(Node a, Node b)
{
	return(a.freq<b.freq);
}



void huffmancode(char arr[],int freq[],int size)
{
	

    Node *huffnode = new Node[size]();

    for(int i=0;i<size;i++)
    {
    	huffnode[i].character=arr[i];
    	huffnode[i].freq=freq[i];
    }

    sort(huffnode,huffnode+size,comp);

    for(int i=0;i<size;i++)
	{
		cout<< huffnode[i].character<<"\n";
	}


	int tempsize=size;

	Node *templeafnodes=new Node[tempsize]() ; // This is array type node  

	for(int i=0;i<tempsize;i++)
    {
    	templeafnodes[i]=huffnode[i];
    }

        while(tempsize!=1)
        {
		   sort(templeafnodes,templeafnodes+tempsize,comp);

		   int InteNodeFreq=templeafnodes[0].freq+templeafnodes[1].freq;

      	   char intechar='$';
           Node *Intenode=new Node();
      	   Intenode=newNode(intechar,InteNodeFreq);   //here I have declared a Node 

      	   Node *temp0=&templeafnodes[0];
      	   Node *temp1=&templeafnodes[1];

		

      	   Intenode->left=new Node(*temp0);      //Here I want too put templeafnodes[0] in left of Intenode
      	   Intenode->right=new Node(*temp1);     ////Here I want too put templeafnodes[1] in right of Intenode

            //Now I want to put Intenode into node type array  in position of templeafnodes[0] position

            templeafnodes[0].character=Intenode->character;
	        templeafnodes[0].freq=Intenode->freq;
	        templeafnodes[0].left=Intenode->left;
	        templeafnodes[0].right=Intenode->right;
	        //cout<<templeafnodes[0].character<<"\n";
            

	        //cout<<(templeafnodes[1].left)->freq<<"\n";
            if(tempsize>2)
            {
	          for(int i=2;i<tempsize;i++)
	           {


                  Node *tempa=&templeafnodes[i];
                  templeafnodes[i-1].character=tempa->character;
	              templeafnodes[i-1].freq=tempa->freq;
	              templeafnodes[i-1].left=tempa->left;
	              templeafnodes[i-1].right=tempa->right;
	        	//cout<<templeafnodes[i].character<<"\n";
	           }
	       }
	       tempsize--;

	       for(int i=0;i<tempsize;i++)
	       {
	       	cout<<templeafnodes[i].freq << "\t";
	       }
	       cout<<"\n";
	   }

        Node *Printcode=&templeafnodes[0];
        int arrrr[50]={0};
        int top=0;
	    Printcodes(Printcode,arrrr,top)  ;
      



 }







int main()
{
	char arr[]={'a','b','c','d','e','f'};
	int freq[]={5, 9, 12, 13, 16, 45} ;
	int size=sizeof(freq)/sizeof(freq[0]);

	huffmancode(arr,freq,size);
    return 0; 


}