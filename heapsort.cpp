#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void heapify(int arr[], int n, int i)
{
	int largest, l, r;
	largest=i;
	l=2*i;
	r=l+1;
	if((l<=n) && (arr[largest]>arr[l]))
		largest=l;
	if((r<=n) && (arr[largest]>arr[r]))
		largest=r;
	if(largest!=i)
	{
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

void heap(int arr[], int n)
{
	for(int i=n/2;i>=0;--i)
		heapify(arr, n, i);
	for(int i=n;i>=1;--i)
	{
		swap(&arr[i], &arr[1]);
		heapify(arr, n, 1);
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
	heap(arr, n-1);
	cout<<"\nSorted elements are: ";
	for(int i=0;i<n;++i)
		cout<<arr[i]<<"  ";
	cout<<endl;
	return 0;
}
