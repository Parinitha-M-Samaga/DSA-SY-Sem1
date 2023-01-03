//SYCOD214
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n, ch, key, flag=0;
	cout<<"Enter the number of elements in the array: ";
	cin>>n;
	int arr[n];
	cout<<"\nEnter elements of the array: ";
	for(int i=0;i<n;++i)
		cin>>arr[i];
	while(1)
	{
		cout<<"\nMenu:";
		cout<<"\n1. Display the entered array.";
		cout<<"\n2. Search for an element in the array.";
		cout<<"\n3. Find the smallest and the largest element.";
		cout<<"\n4. Swap two elements.";
		cout<<"\n5. Display reversed array.";
		cout<<"\n6. Display the Intersection of two arrays.";
		cout<<"\n7. Display the Union of two arrays.";
		cout<<"\n8. Exit.";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				cout<<"\nThe entered array is:\n";
				for(int i=0;i<n;++i)
					cout<<arr[i]<<" ";
				cout<<endl;
				continue;
			}
			
			case 2:
			{
				cout<<"\nEnter the element you want to search for: ";
				cin>>key;
				for(int i=0;i<n;++i)
				{
					if(arr[i]==key)
					{
						cout<<"\n"<<key<<" was found at position "<<i+1<<endl;
						flag=1;
					}
				}
				if(flag!=1)
					cout<<endl<<key<<" is not present in the array.\n";
				continue;
			}
				
			case 3:
			{
				int mini=arr[0], maxi=arr[0];
				for(int i=0;i<n;++i)
				{
					if(mini>arr[i])
						mini=arr[i];
					else if(maxi<arr[i])
						maxi=arr[i];
				}
				cout<<"\nThe smallest element in the array is: "<<mini<<endl;
				cout<<"\nThe largest element in the array is: "<<maxi<<endl;
				continue;
			}
			
			case 4:
			{	int sw1, sw2, i1, i2, temp;
				int arrtemp[n];
				cout<<"\nEnter the two elements to be swapped: ";
				cin>>sw1>>sw2;
				for(int i=0;i<n;++i)
					arrtemp[i]=arr[i];
				for(int i=0;i<n;++i)
				{
					if(sw1==arr[i])
					{
						i1=i;
						break;
					}
				}
				for(int i=0;i<n;++i)
				{
					if(sw2==arr[i])
					{
						i2=i;
						break;
					}
				}
				temp=arrtemp[i1];
				arrtemp[i1]=arrtemp[i2];
				arrtemp[i2]=temp;
				cout<<"\nThe array after swapping the elements is:\n";
				for(int i=0;i<n;++i)
					cout<<arrtemp[i]<<" ";
				cout<<endl;
				//delete[] arrtemp;
				continue;
			}
			
			case 5:
			{
				cout<<"\nThe reversed array is:\n";
				for(int i=n-1;i>=0;--i)
					cout<<arr[i]<<" ";
				cout<<endl;
				continue;
			}
			
			case 6:
			{
				int ns, i;
				cout<<"\nEnter the number of elements in the second array: ";
				cin>>ns;
				int arr2[ns];
				cout<<"\nEnter elements of the second array: ";
				for(i=0;i<ns;++i)
					cin>>arr2[i];
				vector <int> arrt1, arrt2;
				int temp1=0, temp2=0;
				for(i=0;i<n;++i)
				{
					flag=0;
					for(int j=i+1;j<n;++j)
					{
						if(arr[i]==arr[j])
							flag=1;
					}
					if(flag==0)
					{
						++temp1;
						arrt1.push_back(arr[i]);
					}
				}
				for(i=0;i<ns;++i)
				{
					flag=0;
					for(int j=i+1;j<ns;++j)
					{
						if(arr2[i]==arr2[j])
							flag=1;
					}
					if(flag==0)
					{
						++temp2;
						arrt2.push_back(arr2[i]);
					}
				}
				int buf=0;
				for(i=0;i<temp2;++i)
				{
					flag=0;
					for(int j=0;j<temp1;++j)
					{
						if(arrt2[i]==arrt1[j])
							flag=1;
					}
					if(flag==0)
						++buf;
				}
				int count=temp1+buf;
				int intersection[count];
				for(i=0;i<temp1;++i)
					intersection[i]=arrt1[i];
				int t=i;
				for(i=0;i<temp2;++i)
				{
					flag=0;
					for(int j=0;j<temp1;++j)
					{
						if(arrt2[i]==arrt1[j])
							flag=1;
					}
					if(flag==0)
					{
						intersection[t]=arrt2[i];
						++t;
					}
				}
				cout<<"\nThe intersection of the two arrays is:\n";
				for(int i=0;i<count;++i)
					cout<<intersection[i]<<" ";
				cout<<endl;
				continue;
			}
			
			case 7:
			{
				int ns;
				cout<<"\nEnter the number of elements in the second array: ";
				cin>>ns;
				int arr2[ns];
				cout<<"\nEnter elements of the second array: ";
				for(int i=0;i<ns;++i)
					cin>>arr2[i];
				vector <int> arrt1, arrt2;
				int temp1=0, temp2=0;
				for(int i=0;i<n;++i)
				{
					flag=0;
					for(int j=i+1;j<n;++j)
					{
						if(arr[i]==arr[j])
							flag=1;
					}
					if(flag==0)
					{
						++temp1;
						arrt1.push_back(arr[i]);
					}
				}
				for(int i=0;i<ns;++i)
				{
					flag=0;
					for(int j=i+1;j<ns;++j)
					{
						if(arr2[i]==arr2[j])
							flag=1;
					}
					if(flag==0)
					{
						++temp2;
						arrt2.push_back(arr2[i]);
					}
				}
				int unc=0;
				vector <int> Union;
				for(int i=0;i<temp1;++i)
				{
					flag=0;
					for(int j=0;j<temp2;++j)
					{
						if(arrt1.at(i)==arrt2.at(j))
							flag=1;
					}
					if(flag==1)
					{
						++unc;
						Union.push_back(arrt1.at(i));
					}
				}
				cout<<"\nThe union of the two arrays is:\n";
				for(int i=0;i<unc;++i)
					cout<<Union[i]<<" ";
				arrt1.clear();
				arrt2.clear();
				cout<<endl;
				continue;
			}
			
			case 8:
				cout<<"\nThank you!\n";
				return 0;
			
			default:
				cout<<"\nPlease enter a valid choice.\n";
				continue;
		}
	}
	return 0;
}
