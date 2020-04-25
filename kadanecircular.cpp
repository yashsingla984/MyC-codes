#include <iostream>
#include <bits/stdc++.h> 
#include <vector>

using namespace std;

int kadane(int a[],int n)
{
	int max_so_far=0;
	int max_array_sum=0;

	for(int i=0;i<n;i++)
	{
		max_array_sum=a[i]+max_array_sum;
		if(max_so_far<max_array_sum)
		{
			max_so_far=max_array_sum;
		}
		if(max_array_sum<0)
		{
			max_array_sum=0;
		}
	}

	return max_so_far;
}


int main() 
{ 
    int a[] = {12, -5, 4, -8, 11}; 
    int sum=0;
    int n = sizeof(a)/sizeof(a[0]); 
    int max_sum_pos = kadane(a, n); 

    for(int i=0;i<n;i++)
    {
    	sum=sum+a[i];
    	a[i]=-a[i];
    }

    int max_sum_neg =kadane(a, n);

    //we want this sum-(-max_sum_neg)
    max_sum_neg=sum+max_sum_neg;

    if(max_sum_neg<max_sum_pos)
    {
    	cout << "Maximum contiguous sum is " << max_sum_pos;
    } 
    else
    {
    	 cout << "Maximum contiguous sum is " << max_sum_neg;
    }
    return 0; 
} 