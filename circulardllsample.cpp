#include<iostream>
using namespace std;

class CDNode
{
	public:
		int data;
		CDNode *prev;
		CDNode *next;
};

class CDLlist
{
	CDNode *head;
	public:
		CDNode * getnode();
		void append(CDNode *);
		void create();
		void display();
		CDLlist()
		{
			head=NULL;
		}
};

CDNode * CDLlist::getnode()
{
	CDNode *newnode;
	newnode=new CDNode;
	cout<<"\nEnter data: ";
	cin>>newnode->data;
	newnode->prev=NULL;
	newnode->next=NULL;
	return newnode;
}

void CDLlist::append(CDNode *newnode)
{
	if(head==NULL)
		head=newnode;
	else
	{
		CDNode *temp=head;
		while(temp->next!=head)
			temp=temp->next;
		temp->next=newnode;
		newnode->prev=newnode;
	}
	newnode->next=head;
}

void CDLlist::create()
{
	int ch;
	while(1)
	{
		cout<<"\nNew node? (0/1): ";
		cin>>ch;
		if(ch==1)
		{
			CDNode *newnode=getnode();
			append(newnode);
		}
		else if(ch==0)
			break;
		else
			cout<<"\nInvalid choice\n";
	}
}

void CDLlist::display()
{
	CDNode *temp=head;
	while(temp->next!=head)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<temp->data<<endl;
}

int main()
{
	CDLlist n;
	n.create();
	n.display();
	return 0;
}
