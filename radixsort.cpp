#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

void countsort(int arr[],int size,int exp)
{
	int arrA[size]={0};
  
  //here now we sort it with decimal place

  	int countsize[10]={0};

  	for(int i=0;i<size;i++)
  	{
     countsize[(arr[i]/exp)%10]++;
  	}

  //now we add all the countsize 

    for(int i=1;i<10;i++)
  	{
     countsize[i]=countsize[i]+countsize[i-1];
  	}

  	//now we sort the numbers with decimal place

  	for(int k=size-1;k>=0;k--)
  	{
  		int place=0;
  		place=countsize[(arr[k]/exp)%10]-1;
  		arrA[place]=arr[k];
  		countsize[(arr[k]/exp)%10]--;
  	}

  	for(int i=0;i<size;i++)
  	{
     arr[i]=arrA[i];
  	}


  }

void radixsort(int arr[],int size,int maximum)
{
  int digitcount=0;
  int a=maximum;
  while(a>0)
  {
  	digitcount=digitcount+1;
  	a=a/10;
  }
  int totalcount=digitcount;

  int exp=1;

  for(int i=0;i<totalcount;i++)
  {
    countsort(arr,size,exp);
  	exp=exp*10;

  }

}

int main()
{
	int arr[]={2,5,1,7,6,51,43,100,4,34,81,9,1,33};
	int size=sizeof(arr)/sizeof(arr[0]);
	cout<<size<< "\n";

	int *max;
	max=max_element(arr,arr+size);
	int a=*max;
	radixsort(arr,size,a);

	for(int i=0;i<size;i++)
	{
		cout<< arr[i]<<" ";
	}
}