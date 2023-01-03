#include<iostream>
using namespace std;

class DNode
{
	public:
		int data;
		DNode *prev;
		DNode *next;
};

class DLlist
{
	DNode *head;
	public:
		DNode * getnode();
		void append(DNode *);
		void create();
		void display();
		void insert();
		DLlist()
		{
			head=NULL;
		}
};

DNode * DLlist::getnode()
{
	DNode *newnode=new DNode;
	cout<<"\nEnter data: ";
	cin>>newnode->data;
	newnode->prev=NULL;
	newnode->next=NULL;
	return newnode;
}

void DLlist::append(DNode *newnode)
{
	DNode *temp=head;
	if(head==NULL)
		head=newnode;
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newnode;
		newnode->prev=temp;
	}
}

void DLlist::create()
{
	int ch;
	while(1)
	{
		cout<<"\nNew node? (0/1): ";
		cin>>ch;
		if(ch==1)
		{
			DNode *newnode=new DNode;
			newnode=getnode();
			append(newnode);
		}
		else if(ch==0)
			break;
		else
			cout<<"\nInvalid choice\n";
	}
}

void DLlist::display()
{
	DNode *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}

void DLlist::insert()
{
	while(1)
	{
		int ch, flag=0;
		cout<<"\nMore node? (0/1): ";
		cin>>ch;
		if(ch==1)
		{
			DNode *newnode=getnode(), *temp=head;
			while(temp!=NULL)
			{
				if((temp->data)>=(newnode->data))
				{
					DNode *curr=temp->prev;
					curr->next=newnode;
					newnode->prev=curr;
					temp->prev=newnode;
					newnode->next=temp;
					flag=1;
					break;
				}
				else
					temp=temp->next;
			}
			if(flag==0)
				append(newnode);
		}
		else if(ch==0)
			break;
		else
			cout<<"\nInvalid choice\n";
	}
	display();
}

int main()
{
	DLlist n;
	n.create();
	n.display();
	n.insert();
	return 0;
}
