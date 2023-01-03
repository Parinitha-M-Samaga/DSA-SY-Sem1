//SYCOD214
#include <iostream>
using namespace std;

class Dnode
{
	public:
		int data;
		Dnode *prev;
		Dnode *next;
};

class Dlist
{
	Dnode *head;
	Dnode *tail;
	public:
		Dnode * getnode();
		void append(Dnode *);
		void create();
		void display();
		int search(int);
		void insert();
		void delnode();
		Dlist()
		{
			head=NULL;
			tail=NULL;
		}
};

Dnode * Dlist::getnode()
{
	Dnode * newnode;
	newnode=new Dnode;
	cout<<"\nEnter data: ";
	cin>>newnode->data;
	newnode->prev=NULL;
	newnode->next=NULL;
	return newnode;
}

void Dlist::append(Dnode *newnode)
{
	if(head==NULL)
		head=newnode;
	else
	{
		Dnode *temp=head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newnode;
		newnode->prev=temp;
	}
	tail=newnode;
}

void Dlist::create()
{
	int choice;
	while(1)
	{
		cout<<"\nDo you want to enter a new node? (0/1): ";
		cin>>choice;
		if(choice==1)
		{
			Dnode * newnode;
			newnode=getnode();
			append(newnode);
		}
		else if(choice==0)
			break;
		else
			cout<<"\nInvalid choice.\n";
	}
}

void Dlist::display()
{
	Dnode *temp=head;
	if(temp==NULL)
		cout<<"\nEmpty list!\n";
	else
	{
		cout<<"\nHead has element: "<<head->data<<endl;
		while(temp!=NULL)
		{
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<"NULL";
		cout<<"\nTail has element: "<<tail->data<<endl;
	}
}

int Dlist::search(int ele)
{
	int loc, count=1, flag=0;
	Dnode *temp=head;
	if(temp==NULL)
		loc=-1;
	else
	{
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
			loc=-1;
	}
	return loc;
}

void Dlist::insert()
{
	int choice;
	Dnode *newnode;
	cout<<"\nMenu:";
	cout<<"\n1. Insert at the beginning.";
	cout<<"\n2. Insert at a particular position.";
	cout<<"\n3. Insert at the end.";
	cout<<"\nEnter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
			newnode=getnode();
			newnode->next=head;
			head->prev=newnode;
			head=newnode;
			break;
		}
		       
		case 2:
		{
			int pos, flag=0, count=1;
			Dnode *temp=head;
			cout<<"\nEnter position: ";
			cin>>pos;
			while(count!=pos)
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
				cout<<"\nPosition not found!\n";
			else
			{
				newnode=getnode();
				(temp->prev)->next=newnode;
				newnode->next=temp;
				temp->prev=newnode;
			}
			break;
		}
		   
		case 3:
		{
			newnode=getnode();
			newnode->prev=tail;
			tail->next=newnode;
			tail=newnode;
			break;
		}
		      
		default:
			cout<<"\nInvalid choice!\n";
	}
}

void Dlist::delnode()
{
	int choice;
	Dnode *curr=head;
	cout<<"\nMenu:";
	cout<<"\n1. Delete the first element.";
	cout<<"\n2. Delete a particular element.";
	cout<<"\n3. Delete the last element.";
	cout<<"\nEnter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
			head=head->next;
			head->prev=NULL;
			delete curr;
			break;
		}
		       
		case 2:
		{
			int ele, loc, flag=0, count=1;
			cout<<"\nEnter element to delete: ";
			cin>>ele;
			loc=search(ele);
			if(loc==-1)
				cout<<"\nElement not found!\n";
			else
			{
				while(count!=loc)
				{
					curr=curr->next;
					if(curr->next==NULL)
					{
					flag=1;
					break;
					}
					++count;
				}
				if(flag==1)
					cout<<"\nElement not found!\n";
				else
				{
					(curr->prev)->next=curr->next;
					(curr->next)->prev=curr->prev;
					delete curr;
				}
			}
			break;
		}
		       
		case 3:
		{
			curr=tail;
			(tail->prev)->next=tail->next;
			tail=tail->prev;
			delete curr;
			break;
		}
		    
		default:
			cout<<"\nInvalid choice!\n";
	}
}

int main()
{
	Dlist dll;
	int choice;
	dll.create();
	while(1)
	{
		cout<<"\nMenu:";
		cout<<"\n1. Display the list.";
		cout<<"\n2. Search for an element. ";
		cout<<"\n3. Insert an element.";
		cout<<"\n4. Delete an element.";
		cout<<"\n5. Exit.";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				dll.display();
				continue;
				 
			case 2:
			{
				int ele, loc;
				cout<<"\nEnter an element to search for: ";
				cin>>ele;
				loc=dll.search(ele);
				if(loc==-1)
					cout<<"\nElement not found!\n";
				else
					cout<<"\nElement "<<ele<<" found at location "<<loc<<"."<<endl;
				continue;
			}
				   
			case 3:
				dll.insert();
				dll.display();
				continue;
				   
			case 4:
				dll.delnode();
				dll.display();
				continue;
				   
			case 5:
				cout<<"\nThank you!\n";
				return 0;
				   
			default:
				cout<<"\nInvalid choice!\n";
		}
	}
	return 0;
}
