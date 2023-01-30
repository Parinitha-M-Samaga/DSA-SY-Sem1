#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void shell(int arr[], int n)
{
	for(int gap=n/2;gap>0;gap/=2)
	{
		for(int i=gap;i<n;++i)
		{
			for(int j=i-gap;j>=0;--j)
			{
				if(arr[j]<arr[j+gap])
					break;
				else
					swap(&arr[j], &arr[j+gap]);
			}
		}
	}
}

int main()
{
	int n;
	cout<<"\nEnter number of terms: ";
	cin>>n;
	int arr[n];
	cout<<"\nEnter data: ";
	for(int i=0;i<n;++i)
		cin>>arr[i];
	shell(arr, n);
	cout<<"\nSorted elements: ";
	for(int i=0;i<n;++i)
		cout<<arr[i]<<"  ";
	cout<<endl;
	return 0;
}
