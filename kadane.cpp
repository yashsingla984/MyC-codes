#include <iostream>
#include <bits/stdc++.h> 
#include <vector>

using namespace std;

int maxSubArraySum(int a[],int n)
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
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
    int n = sizeof(a)/sizeof(a[0]); 
    int max_sum = maxSubArraySum(a, n); 
    cout << "Maximum contiguous sum is " << max_sum; 
    return 0; 
} 