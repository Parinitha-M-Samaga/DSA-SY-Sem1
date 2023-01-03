//SYCOD214
#include <iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node * next;
};

class Llist
{
	Node * tail;
	public:
		Node * head;
		void create();
		void display();
		Node * getnode();
		int search(int);
		void insert();
		void delnode();
		void reverse(Node *);
		Llist()
		{
			head=NULL;
			tail=NULL;
		}
};

Node * Llist::getnode()
{
	Node * newnode;
	newnode=new Node;
	cout<<"\nEnter data: ";
	cin>>newnode->data;
	newnode->next=NULL;
	return(newnode);
}

void Llist::create()
{
	Node * newnode;
	int choice;
	while(1)
	{
		cout<<"\nDo you want to enter a new node?(0/1) :";
		cin>>choice;
		if(choice==1)
		{
			newnode=getnode();
			if(head==NULL)
				head=newnode;
			else
			{
				Node * temp;
				temp=head;
				while(temp->next!=NULL)
					temp=temp->next;
				temp->next=newnode;
			}
			tail=newnode;
		}
		else if(choice==0)
			break;
		else
			cout<<"\nEnter a valid choice.\n";
	}
}

void Llist::display()
{
	Node * temp;
	temp=head;
	if(temp==NULL)
		cout<<"\nEmpty list.\n";
	else
	{
		cout<<"\nHead has "<<head->data;
		cout<<"\nElements are:\n";
		while(temp!=NULL)
		{
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<"NULL";
		cout<<"\nTail has "<<tail->data;
		cout<<endl<<"End of list.";
	}
}

int Llist::search(int e)
{
	Node * temp;
	int flag=0, count=1;
	temp=head;
	if(temp==tail && temp!=NULL)
	{
		if(temp->data==e)
			return 1;
		else
			return -1;
	}
	while(temp!=NULL)
	{
		if(temp->data!=e)
		{
			temp=temp->next;
			++count;
		}
		else
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		return count;
	else
		return -1;
}

void Llist::insert()
{
	Node *newnode, *temp;
	int pos, choice;
	temp=head;
	cout<<"\nMenu:";
	cout<<"\n1.Enter an element at the beginning.";
	cout<<"\n2.Enter an element in between the list.";
	cout<<"\n3.Enter an element at the end.";
	cout<<"\nEnter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
			newnode=getnode();
			newnode->next=head;
			head=newnode;
			break;
		}
		
		case 2:
		{
			cout<<"\nEnter the position where you want to insert the node: ";
			cin>>pos;
			int count=1, flag=1;
			newnode=getnode();
			while(count!=pos-1)
			{
				temp=temp->next;
				if(temp->next==NULL)
				{
					flag=0;
					break;
				}
				++count;
			}
			if(flag==1)
			{
				newnode->next=temp->next;
				temp->next=newnode;
			}
			else
				cout<<"\nPosition not found!\n";
			break;
		}
		
		case 3:
		{
			newnode=getnode();
			newnode->next=tail->next;
			tail->next=newnode;
			tail=newnode;
			break;
		}
		
		default:
			cout<<"\nInvalid choice!\n";
	}
}

void Llist::delnode()
{
	int ele, pos, choice, flag=1, count=1;
	Node *temp, *curr;
	temp=head;
	curr=head;
	cout<<"\n\nMenu:";
	cout<<"\n1.Delete the first element.";
	cout<<"\n2.Delete a specific element.";
	cout<<"\n3.Delete the last element.";
	cout<<"\nEnter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			head=head->next;
			delete curr;
			break;
		
		case 2:
		{
			cout<<"\nEnter the data to be deleted: ";
			cin>>ele;
			pos=search(ele);
			if(pos==-1)
				cout<<"\nElement not found!\n";
			else
			{
				while(count!=pos-1)
				{
					temp=temp->next;
					if(temp->next==NULL)
					{
						flag=0;
						break;
					}
					++count;
				}
				count=1;
				while(count!=pos)
				{
					curr=curr->next;
					if(curr->next==NULL)
					{
						flag=0;
						break;
					}
					++count;
				}
				temp->next=curr->next;
				curr->next=NULL;
				delete curr;
			}
			break;
		}
		
		case 3:
		{
			if(head==tail)
			{
				curr=head;
				head=NULL;
				delete curr;
			}
			else
			{
				curr=tail;
				pos=search(tail->data);
				while(count!=pos-1)
				{
					temp=temp->next;
					++count;
				}
				temp->next=curr->next;
				tail=temp;
				delete curr;
			}
			break;
		}
		
		default:
			cout<<"\nInvalid choice!\n";
	}
}

void Llist::reverse(Node *temp)
{
	if(temp->next==NULL)
		cout<<temp->data<<"->";
	else
	{
		reverse(temp->next);
		cout<<temp->data<<"->";
	}
}

int main()
{
	int choice, found, ele;
	Node n;
	Llist n1;
	n1.create();
	while(1)
	{
		cout<<"\n\nMenu:";
		cout<<"\n1.Display the original linked list.";
		cout<<"\n2.Search for an element.";
		cout<<"\n3.Add a new element.";
		cout<<"\n4.Delete an element.";
		cout<<"\n5.Show the reversed linked list.";
		cout<<"\n6.Exit.";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
			{
				n1.display();
				continue;
			}
			
			case 2:
			{
				cout<<"\nEnter the element you want to search for: ";
				cin>>ele;
				found=n1.search(ele);
				if(found!=-1)
					cout<<"\nFound "<<ele<<" at position "<<found<<"."<<endl;
				else
					cout<<"\nElement not found!\n";
				continue;
			}
			
			case 3:
			{
				n1.insert();
				n1.display();
				continue;
			}
			
			case 4:
			{
				n1.delnode();
				n1.display();
				continue;
			}
			
			case 5:
			{
				cout<<"\nThe reversed list is:\n";
				n1.reverse(n1.head);
				cout<<"NULL";
				continue;
			}
			
			case 6:
			{
				cout<<"\nThank you!\n";
				return 0;
			}
			
			default:
				cout<<"\nEnter a valid choice.\n";
		}
	}
	return 0;
}
