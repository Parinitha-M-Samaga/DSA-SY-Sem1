//SYCOD214
#include<iostream>
using namespace std;

class TBTnode
{
        public:
                int data;
                bool lbit;
                bool rbit;
                TBTnode* lchild;
                TBTnode* rchild;
                TBTnode()
                {
                        lbit=1;
                        rbit=1;
                        lchild=NULL;
                        rchild=NULL;
                }
};

class TBTop
{
        TBTnode *head, *root;
        public:
                TBTnode* getnode();
                void insert();
                void search();
                void inorder_traversal();
                void preorder_traversal();
                TBTop()
                {
                	 root=new TBTnode;
                        root=NULL;
                        head=new TBTnode;
                        head->data=-1;
                        head->lchild=head->rchild=head;
                }
};

TBTnode* TBTop::getnode()
{
	TBTnode *newnode;
	newnode=new TBTnode;
	cout<<"\nEnter data: ";
	cin>>newnode->data;
	return newnode;
}

void TBTop::insert()
{
	TBTnode *newnode;
	newnode=getnode();
	if(root==NULL)
	{
		root=newnode;
		root->lchild=root->rchild=head;
		head->lbit=0;
		head->lchild=root;
	}
	else
	{
		TBTnode *temp=root;
		while(temp!=head)
		{
			if((temp->data)==(newnode->data))
			{
				cout<<"\nRedundant data!\n";
				break;
			}
			else if((temp->data)>(newnode->data))
			{
				if(temp->lbit==1)
				{
					newnode->lchild=temp->lchild;
					newnode->rchild=temp;
					temp->lchild=newnode;
					temp->lbit=0;
					break;
				}
				else
					temp=temp->lchild;
			}
			else if((temp->data)<(newnode->data))
			{
				if(temp->rbit==1)
				{
					newnode->rchild=temp->rchild;
					newnode->lchild=temp;
					temp->rchild=newnode;
					temp->rbit=0;
					break;
				}
				else
					temp=temp->rchild;
			}
		}
	}
}

void TBTop::search()
{
	if(head->lchild==head)
	{
		cout<<"\nTree is empty!\n";
		return;
	}
	int value;
	TBTnode *temp=root;
	cout<<"\nEnter value you want to search for: ";
	cin>>value;
	while(temp!=head)
	{
		if((temp->data)==value)
		{
			cout<<"\nData found!\n";
			return;
		}
		else if(temp->lbit==1 && temp->rbit==1)
			break;
		else if((temp->data)>value)
			temp=temp->lchild;
		else if((temp->data)<value)
			temp=temp->rchild;
	}
	cout<<"\nData not found!\n";
}

void TBTop::inorder_traversal()
{
	if(root==NULL)
	{
		cout<<"\nTree is empty!\n";
		return;
	}
	TBTnode *temp=root;
	int flag=0;
	cout<<"\nThe nodes of the tree in ascending order is:  ";
	while(temp!=head)
	{
		if(temp->lbit==0 && flag==0)
			temp=temp->lchild;
		else
		{
			cout<<temp->data<<"  ";
			if(temp->rbit==0)
			{
				temp=temp->rchild;
				flag=0;
			}
			else
			{
				temp=temp->rchild;
				flag=1;
			}
		}
	}
}

void TBTop::preorder_traversal()
{
	if(root==NULL)
	{
		cout<<"\nTree is empty!\n";
		return;
	}
	TBTnode *temp=root;
	int flag=0;
	cout<<"\nThe nodes of the tree in preorder is:  ";
	while(temp!=head)
	{
		if(flag==0)
			cout<<temp->data<<"  ";
		if(temp->lbit==0 && flag==0)
			temp=temp->lchild;
		else
		{
			if(temp->rbit==0)
			{
				temp=temp->rchild;
				flag=0;
			}
			else
			{
				temp=temp->rchild;
				flag=1;
			}
		}
	}
}

int main()
{
	TBTop tree;
	int choice;
	while(1)
	{
		cout<<"\nMenu:";
		cout<<"\n1. Insert a node.";
		cout<<"\n2. Search for a data.";
		cout<<"\n3. Display nodes of the tree in ascending order.";
		cout<<"\n4. Display preorder traversal of the tree.";
		cout<<"\n5. Exit";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				tree.insert();
				continue;
			
			case 2:
				tree.search();
				continue;
			
			case 3:
				tree.inorder_traversal();
				continue;
			
			case 4:
				tree.preorder_traversal();
				continue;
			
			case 5:
				cout<<"\nThank you!\n";
				exit(0);
			
			default:
				cout<<"\nInvalid choice!\n";
		}
	}
        return 0;
}
