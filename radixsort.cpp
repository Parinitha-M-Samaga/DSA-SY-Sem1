#include<iostream>
using namespace std;

int getmax(int arr[], int n)
{
	int max=arr[0];
	for(int i=0;i<n;++i)
	{
		if(arr[i]>max)
			max=arr[i];
	}
	return max;
}

void countsort(int arr[], int n, int pos)
{
	int count[10]={0}, b[n];
	for(int i=0;i<n;++i)
		++count[(arr[i]/pos)%10];
	for(int i=1;i<10;++i)
		count[i]+=count[i-1];
	for(int i=n-1;i>=0;--i)
		b[--count[(arr[i]/pos)%10]]=arr[i];
	for(int i=0;i<n;++i)
		arr[i]=b[i];
	for(int i=0;i<n;++i)
		cout<<arr[i]<<"  ";
}

void radix(int arr[], int n)
{
	int max=getmax(arr, n);
	for(int pos=1;max/pos>0;pos*=10)
		countsort(arr, n, pos);
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
	radix(arr, n);
	cout<<"\nSorted elements are: ";
	for(int i=0;i<n;++i)
		cout<<arr[i]<<"  ";
	cout<<endl;
	return 0;
}
