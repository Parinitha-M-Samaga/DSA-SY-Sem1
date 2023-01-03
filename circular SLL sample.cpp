#include<iostream>
using namespace std;

class CNode
{
	public:
		int data;
		CNode *next;
};

class CLlist
{
	CNode *head;
	public:
		void append(CNode *);
		CNode * getnode();
		void create();
		void display();
		CLlist()
		{
			head=NULL;
		}
};

CNode * CLlist::getnode()
{
	CNode *newnode;
	newnode=new CNode;
	cout<<"\nEnter data: ";
	cin>>newnode->data;
	newnode->next=NULL;
	return newnode;
}

void CLlist::append(CNode *newnode)
{
	CNode *temp=head;
	if(head==NULL)
		head=newnode;
	else
	{
		while(temp->next!=head)
			temp=temp->next;
		temp->next=newnode;
	}
	newnode->next=head;
}

void CLlist::create()
{
	int ch;
	while(1)
	{
		cout<<"\nNew node? (0/1): ";
		cin>>ch;
		if(ch==1)
		{
			CNode *newnode;
			newnode=getnode();
			append(newnode);
			display();
		}
		else if(ch==0)
			break;
		else
			cout<<"\nInvald choice!\n";
	}
}

void CLlist::display()
{
	CNode *temp=head;
	while(temp->next!=head)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<temp->data<<endl;
}

int main()
{
	CLlist n;
	n.create();
	return 0;
}
