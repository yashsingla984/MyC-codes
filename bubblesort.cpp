#include <iostream>
using namespace std;

void bubblesort(int arr[],int size)
{
	for(int i=0;i<size-1;i++)
	{
		for(int j=0;j<size-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				//swap the both
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}


int main()
{
	int arr[]={2,5,1,7,6,51,43,100,4};
	int size=sizeof(arr)/sizeof(arr[0]);
	cout<<size;
	bubblesort(arr,size);

	for(int i=0;i<size;i++)
	{
		cout<< arr[i]<<" ";
	}
}