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
		friend void concat(Node *, Node *);
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

void concat(Node *head1, Node *head2)
{
	Llist con;
	Node *temp=head1;
	while(temp!=NULL)
	{
		Node *newnode=new Node;
		newnode->data=temp->data;
		if(con.head==NULL)
			con.head=newnode;
		else
			con.tail->next=newnode;
		con.tail=newnode;
		temp=temp->next;
	}
	temp=head2;
	while(temp!=NULL)
	{
		Node *newnode=new Node;
		newnode->data=temp->data;
		if(con.head==NULL)
			con.head=newnode;
		else
			con.tail->next=newnode;
		con.tail=newnode;
		temp=temp->next;
	}
	con.display();
}

int main()
{
	Llist n1, n2;
	n1.create();
	n2.create();
	concat(n1.head, n2.head);
	return 0;
}
