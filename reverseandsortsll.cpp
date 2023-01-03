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
		void reverse();
		void sort();
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

void Llist::reverse()
{
	Node *prev=NULL, *nextt=NULL, *curr=head;
	while(curr!=NULL)
	{
		nextt=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nextt;
	}
	head=prev;
	display();
}

void Llist::sort()
{
	Node *temp=head;
	while(temp!=NULL)
	{
		Node *curr=temp;
		Node *temp1=curr->next;
		Node *low=temp;
		while(temp1!=NULL)
		{
			if((low->data)>(temp1->data))
				low=temp1;
			temp1=temp1->next;
		}
		int t=low->data;
		low->data=curr->data;
		curr->data=t;
		temp=temp->next;
	}
	display();
}

int main()
{
	Llist n;
	n.create();
	n.display();
	n.reverse();
	n.sort();
	return 0;
}
