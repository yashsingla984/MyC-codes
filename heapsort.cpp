#include <iostream>
using namespace std;

void heapify(int arr[],int n,int largest)
{
	int index=largest;
	int l=2*largest+1;
	int r=2*largest+2;

	if(l<n && arr[l]>arr[largest])
	{
		largest=l;
	}
	if(r<n  && arr[r]>arr[largest])
	{
		largest=r;
	}

	if(largest!=index)
	{
		//swap the index with largest

		int temp=arr[index];
		arr[index]=arr[largest];
		arr[largest]=temp;
		heapify(arr,n,largest);
	}
}


void heapsort(int arr[],int n)
{
	for(int i=((n/2)-1); i>=0;i--)
	{
        heapify(arr,n,i);
	}
	//after we do swap with last element

	int temp=arr[0];
	arr[0]=arr[n-1];
	arr[n-1]=temp;


	for(int newn=n-1;newn>0;newn--)
	{
		heapify(arr,newn,0);

		int temp=arr[0];
	    arr[0]=arr[newn-1];
	    arr[newn-1]=temp;
	}
}


int main()
{
	int arr[]={-30,5,1,7,-20,51,43,100,4};
	int size=sizeof(arr)/sizeof(arr[0]);
	cout<<size<<"\n";
	heapsort(arr,size);

	for(int i=0;i<size;i++)
	{
		cout<< arr[i]<<" ";
	}
}