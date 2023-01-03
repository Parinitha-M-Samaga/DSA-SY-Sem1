#include<iostream>
using namespace std;

class Queue
{
	public:
		int data;
		Queue *next;
};

class Qop
{
	Queue *front, *rear;
	int max=5;
	public:
		int size;
		bool full();
		bool empty();
		void enqueue(int);
		int dequeue();
		void display();
		Qop()
		{
			front=NULL;
			rear=NULL;
			size=-1;
		}
};

bool Qop::full()
{
	if(size==max-1)
		return true;
	else
		return false;
}

bool Qop::empty()
{
	if(front==NULL || size==-1)
		return true;
	else
		return false;
}

void Qop::enqueue(int ele)
{
	if(!full())
	{
		Queue *newnode=new Queue;
		newnode->data=ele;
		if(empty())
			front=newnode;
		else
		{
			Queue *temp=front;
			while(temp->next!=front)
				temp=temp->next;
			temp->next=newnode;
		}
		rear=newnode;
		newnode->next=front;
		++size;
	}
	else
		cout<<"\nQueue Overflow!\n";
}

int Qop::dequeue()
{
	int ret;
	if(!empty())
	{
		Queue *temp=front;
		ret=front->data;
		front=front->next;
		rear->next=front;
		--size;
		delete temp;
	}
	else
		ret=-1;
	return ret;
}

void Qop::display()
{
	Queue *temp=front;
	if(empty())
		cout<<"\nQueue Underflow!\n";
	else
	{
		while(temp->next!=front)
		{
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<temp->data<<endl;
	}
}

int main()
{
	Qop q;
	int ch, ele;
	while(1)
	{
		cout<<"\nNew node? (0/1): ";
		cin>>ch;
		if(ch==1)
		{
			cout<<"\nEnter data: ";
			cin>>ele;
			q.enqueue(ele);
		}
		else if(ch==0)
			break;
		else
			cout<<"\nInvalid choice\n";
	}
	q.display();
	while(1)
	{
		cout<<"\nDelete first node? (0/1): ";
		cin>>ch;
		if(ch==1)
		{
			int pop;
			pop=q.dequeue();
			if(pop!=-1)
				cout<<"\nPopped: "<<pop<<endl;
			else
				cout<<"\nQueue Underflow!\n";
		}
		else if(ch==0)
			break;
		else
			cout<<"\nInvalid choice\n";
		q.display();
	}
	return 0;
}
