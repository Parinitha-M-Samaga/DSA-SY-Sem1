#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
};

class Llist
{
	public:
		Node *head, *tail;
		Node * getnode();
		void append(Node *);
		void create();
		void display();
		void delnode(int);
		void insert(int, int);
		Llist()
		{
			head=NULL;
			tail=NULL;
		}
};

Node * Llist::getnode()
{
	Node *newnode=new Node;
	cout<<"\nEnter data: ";
	cin>>newnode->data;
	newnode->next=NULL;
	return newnode;
}

void Llist::append(Node *newnode)
{
	if(head==NULL)
		head=newnode;
	else
	{
		Node *temp=head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newnode;
	}
	tail=newnode;
}

void Llist::create()
{
	int ch;
	while(1)
	{
		cout<<"\nNew node? (0/1): ";
		cin>>ch;
		if(ch==1)
		{
			Node *newnode;
			newnode=getnode();
			append(newnode);
		}
		else if(ch==0)
			break;
		else
			cout<<"\nInvalid choice.\n";
	}
}

void Llist::display()
{
	Node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}

void Llist::delnode(int ele)
{
	Node *temp=head;
	int flag=0, loc, count=1;
	while(temp!=NULL)
	{
		if(temp->data==ele)
		{
			loc=count;
			flag=1;
			break;
		}
		temp=temp->next;
		++count;
	}
	if(flag==0)
	{
		cout<<"\nElement not found!\n";
		return;
	}
	if(loc==1)
	{
		head=head->next;
		delete temp;
	}
	else
	{
		count=1;
		Node *curr=head;
		while(count!=loc-1)
		{
			curr=curr->next;
			++count;
		}
		curr->next=temp->next;
		delete temp;
	}
	display();
}

void Llist::insert(int ele, int pos)
{
	Node *newnode=new Node;
	newnode->data=ele;
	int count=1, flag=0;
	Node *temp=head;
	while(count!=pos-1)
	{
		temp=temp->next;
		if(temp==NULL)
		{
			flag=1;
			break;
		}
		++count;
	}
	if(flag==1)
	{
		cout<<"\nPosition not found!\n";
		return;
	}
	newnode->next=temp->next;
	temp->next=newnode;
	display();
}

int main()
{
	Llist n;
	n.create();
	n.display();
	for(int i=0;i<2;++i)
	{
		cout<<"\nEnter data and position: ";
		int newele, pos;
		cin>>newele>>pos;
		n.insert(newele, pos);
	}
	for(int i=0;i<2;++i)
	{
		cout<<"\nEnter data to delete: ";
		int ele;
		cin>>ele;
		n.delnode(ele);
	}
	return 0;
}
