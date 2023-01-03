//SYCOD214
#include <iostream>
using namespace std;

class Queue
{
	public:
		int data;
		Queue * next;
};

class Queuenew
{
	Queue *front, *rear;
	int maximum=5;
	int size, frontsz, rearsz;
		public:
		void insert(int ele);
		int delnode();
		int getfront();
		bool empty();
		bool full();
		int currsize();
		void display();
		Queuenew()
		{
			front=NULL;
			rear=NULL;
			size=-1;
			frontsz=-1;
			rearsz=-1;
		}
};

bool Queuenew::full()
{
	if(rearsz==maximum-1)
		return true;
	else
		return false;
}

bool Queuenew::empty()
{
	if(front==NULL)
		return true;
	else
		return false;
}

void Queuenew::insert(int ele)
{
	if(!full())
	{
		Queue * newnode;
		newnode=new Queue;
		newnode->data=ele;
		newnode->next=NULL;
		if(empty())
		{
			front=newnode;
			rear=newnode;
		}
		else
		{
			rear->next=newnode;
			rear=newnode;
		}
		++size;
		++rearsz;
	}
	else
		cout<<"\nQueue Overflow!\n";
}

int Queuenew::delnode()
{
	int deleted;
	if(!empty())
	{
		Queue *temp=front;
		deleted=front->data;
		front=front->next;
		delete temp;
		--size;
		++frontsz;
	}
	else
		deleted=-1;
	return deleted;
}

int Queuenew::getfront()
{
	int ret;
	if(empty())
		ret=-1;
	else
		ret=front->data;
	return (ret);
}

int Queuenew::currsize()
{
	return (size+1);
}

void Queuenew::display()
{
	Queue *temp=front;
	if(full() && frontsz==rearsz)
		cout<<"\nQueue Overflow!\n";
	else if(empty())
		cout<<"\nQueue Underflow!\n";
	else
	{
		cout<<"\nFront: "<<front->data<<endl;
		while(temp!=NULL)
		{
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<"NULL";
		cout<<"\nRear: "<<rear->data<<endl;
	}
}

int main()
{
	Queuenew q;
	int ch, ele;
	while(1)
	{
		cout<<"\nMenu:";
		cout<<"\n1. Insert an element.";
		cout<<"\n2. Delete the frontmost element.";
		cout<<"\n3. Display the queue.";
		cout<<"\n4. Get the frontmost element.";
		cout<<"\n5. Get the current size.";
		cout<<"\n6. Exit";
		cout<<"\nEnter choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				cout<<"\nEnter data: ";
				cin>>ele;
				q.insert(ele);
				q.display();
				continue;
			}
				    
			case 2:
			{
				int deleted=q.delnode();
				if(deleted==-1)
					cout<<"\nQueue Underflow!\n";
				else
				{
					cout<<"\nDeleted element: "<<deleted<<endl;
					q.display();
				}
				continue;
			}
				   
			case 3:
				q.display();
				continue;
				    
			case 4:
			{
				int get=q.getfront();
				if(get==-1)
					cout<<"\nQueue Underflow!\n";
				else
					cout<<"\nElement at the front is: "<<get<<endl;
				continue;
			}
			      
			case 5:
				cout<<"\nQueue size is: "<<q.currsize()<<endl;
				continue;
			    
			case 6:
				return 0;
			       
			default:
				cout<<"\nInvalid choice.\n";
		}
	}
	return 0;
}
