//SYCOD214
#include<iostream>
using namespace std;

class Tnode
{
	public:
		int data;
		Tnode * lchild;
		Tnode * rchild;
		Tnode * next;          //for stack
		int height;
};

class Stackop
{
        Tnode *top;
        public:
                bool empty();
                void push(Tnode*);
                Tnode* pop();
                Stackop()
                {
                        top=NULL;
                }
};

bool Stackop::empty()
{
        if(top==NULL)
                return true;
        else
                return false;
}

void Stackop::push(Tnode* value)
{
        Tnode *newnode;
        newnode=new Tnode;
        newnode=value;
        if(empty())
                newnode->next=NULL;
        else
                newnode->next=top;
        top=newnode;
}
       
Tnode* Stackop::pop()
{
        Tnode* value;
        if(empty())
        {
                value->data=-1;
                value->next=value->lchild=value->rchild=NULL;
        }
        else
        {
                value=top;
                top=top->next;
        }
        return value;
}

class Tnop
{
	public:
		Tnode * root;
		int heightcal(Tnode *);
		int balfactor(Tnode *);
		Tnode * ll_shift(Tnode *);
		Tnode * rr_shift(Tnode *);
		Tnode * lr_shift(Tnode *);
		Tnode * rl_shift(Tnode *);
		Tnode * insert(Tnode *, int);
		void search();
		Tnode * delnode(Tnode *, int);
		void inorder_traversal();
		void preorder_traversal();
		Tnop()
		{
			root=NULL;
		}
};

int Tnop::heightcal(Tnode *node)
{
	int ht;
	if(node==NULL)
		ht=0;
	else if(node->lchild && node->rchild)
	{
		if((node->lchild->height)>(node->rchild->height))
			ht=(node->lchild->height)+1;
		else
			ht=(node->rchild->height)+1;
	}
	else if(node->lchild && (node->rchild==NULL))
		ht=(node->lchild->height)+1;
	else if(node->rchild && (node->lchild==NULL))
		ht=(node->rchild->height)+1;
	else
		ht=1;
	return ht;
}

int Tnop::balfactor(Tnode *node)
{
	int bal;
	if(node->lchild && node->rchild)
		bal=((node->lchild->height)-(node->rchild->height));
	else if(node->lchild && (node->rchild==NULL))
		bal=(node->lchild->height);
	else if(node->rchild && (node->lchild==NULL))
		bal=(-(node->rchild->height));
	return bal;
}

Tnode * Tnop::ll_shift(Tnode *node)
{
	Tnode *temp1, *temp2, *temp3;
	temp1=node;
	temp2=node->lchild;
	temp3=(node->lchild)->lchild;
	int ht1=temp1->height-1, ht2=temp2->height-1;
	temp1->lchild=temp2->rchild;
	temp2->rchild=temp1;
	temp1->height=ht2;
	temp2->height=ht1;
	temp3->height=ht2;
	return temp2;
}

Tnode * Tnop::rr_shift(Tnode *node)
{
	Tnode *temp1, *temp2, *temp3;
	temp1=node;
	temp2=node->rchild;
	temp3=(node->rchild)->rchild;
	int ht1=temp1->height-1, ht2=temp2->height-1;
	temp1->rchild=temp2->lchild;
	temp2->lchild=temp1;
	temp1->height=ht2;
	temp2->height=ht1;
	temp3->height=ht2;
	return temp2;
}

Tnode * Tnop::lr_shift(Tnode *node)
{
	Tnode *temp1, *temp2, *temp3;
	temp1=node;
	temp2=node->lchild;
	temp3=(node->lchild)->rchild;
	int ht1=temp1->height-1, ht2=temp2->height-1;
	temp1->lchild=temp3->rchild;
	temp2->rchild=temp3->lchild;
	temp3->lchild=temp2;
	temp3->rchild=temp1;
	temp1->height=ht2;
	temp2->height=ht2;
	temp3->height=ht1;
	return temp3;
}

Tnode * Tnop::rl_shift(Tnode *node)
{
	Tnode *temp1, *temp2, *temp3;
	temp1=node;
	temp2=node->rchild;
	temp3=(node->rchild)->lchild;
	int ht1=temp1->height-1, ht2=temp2->height-1;
	temp1->rchild=temp3->lchild;
	temp2->lchild=temp3->rchild;
	temp3->rchild=temp2;
	temp3->lchild=temp1;
	temp1->height=ht2;
	temp2->height=ht2;
	temp3->height=ht1;
	return temp3;
}

Tnode * Tnop::insert(Tnode *node, int ndata)
{
	if(node==NULL)
	{
		Tnode * newnode;
		newnode=new Tnode;
		newnode->data=ndata;
		newnode->lchild=newnode->rchild=NULL;
		newnode->height=1;
		node=newnode;
		return node;
	}
	else
	{
		if(ndata<(node->data))
			node->lchild=insert(node->lchild, ndata);
		else
			node->rchild=insert(node->rchild, ndata);
	}
	node->height=heightcal(node);
	if(balfactor(node)==2 && balfactor(node->lchild)==1)
	{
		cout<<"\nLL shift.\n";
		node=ll_shift(node);
	}
	else if(balfactor(node)==-2 && balfactor(node->rchild)==-1)
	{
		cout<<"\nRR shift.\n";
		node=rr_shift(node);
	}
	else if(balfactor(node)==2 && balfactor(node->lchild)==-1)
	{
		cout<<"\nLR shift.\n";
		node=lr_shift(node);
	}
	else if(balfactor(node)==-2 && balfactor(node->rchild)==1)
	{
		cout<<"\nRL shift.\n";
		node=rl_shift(node);
	}
	return node;
}

void Tnop::search()
{
        if(root==NULL)
        {
                cout<<"\nTree is empty!\n";
                return;
        }
        int value, flag=0;
        cout<<"\nEnter the data you want to search for: ";
        cin>>value;
        Tnode *temp=root;
        while(temp!=NULL)
        {
                if(value==(temp->data))
                {
                        cout<<"\nData found!\n";
                        flag=1;
                        break;
                }
                else if(value<(temp->data))
                        temp=temp->lchild;
                else if(value>(temp->data))
                        temp=temp->rchild;
        }
        if(flag==0)
                cout<<"\nData not found!\n";
}

Tnode * Tnop::delnode(Tnode *node, int key)
{
	if(node->lchild==NULL && node->rchild==NULL)
	{
		if(node==root)
			root=NULL;
		delete node;
		return NULL;
	}
	if(key<node->data)
		node->lchild=delnode(node->lchild, key);
	else if(key>node->data)
		node->rchild=delnode(node->rchild, key);
	else
	{
		Tnode *temp;
		if(node->lchild!=NULL)
		{
			temp=node->lchild;
			while(temp->rchild!=NULL)
				temp=temp->rchild;
			node->data=temp->data;
			node->lchild=delnode(node->lchild, temp->data);
		}
		else
		{
			temp=node->rchild;
			while(temp->lchild!=NULL)
				temp=temp->lchild;
			node->data=temp->data;
			node->rchild=delnode(node->rchild, temp->data);
		}
	}
	node->height=heightcal(node);
	if((balfactor(node)==2 && balfactor(node->lchild)==1) || (balfactor(node)==2 && balfactor(node->lchild)==0))
	{
		cout<<"\nLL shift.\n";
		node=ll_shift(node);
	}
	else if(balfactor(node)==-2 && balfactor(node->rchild)==-1 || (balfactor(node)==-2 && balfactor(node->rchild)==0))
	{
		cout<<"\nRR shift.\n";
		node=rr_shift(node);
	}
	else if(balfactor(node)==2 && balfactor(node->lchild)==-1)
	{
		cout<<"\nLR shift.\n";
		node=lr_shift(node);
	}
	else if(balfactor(node)==-2 && balfactor(node->rchild)==1)
	{
		cout<<"\nRL shift.\n";
		node=rl_shift(node);
	}
	return node;
}

void Tnop::inorder_traversal()
{
        if(root==NULL)
        {
                cout<<"\nTree is empty!\n";
                return;
        }
        cout<<"\nThe inorder traversal is:  ";
        Tnode *temp=root;
        Stackop stack;
        while(1)
        {
                while(temp!=NULL)
                {
                        stack.push(temp);
                        temp=temp->lchild;
                }
                if(stack.empty())
                        return;
                temp=stack.pop();
                cout<<temp->data<<"  ";
                temp=temp->rchild;
        }
        cout<<endl;
}

void Tnop::preorder_traversal()
{
        if(root==NULL)
        {
                cout<<"\nTree is empty!\n";
                return;
        }
        cout<<"\nThe preorder traversal is:  ";
        Tnode *temp=root;
        Stackop stack;
        while(1)
        {
                while(temp!=NULL)
                {
                        stack.push(temp);
                        cout<<temp->data<<"  ";
                        temp=temp->lchild;
                }
                if(stack.empty())
                        return;
                temp=stack.pop();
                temp=temp->rchild;
        }
        cout<<endl;
}

int main()
{
        Tnop avltree;
        int choice;
        while(1)
        {
                cout<<"\nMenu:";
                cout<<"\n1. Insert a node.";
                cout<<"\n2. Search for a node.";
                cout<<"\n3. Delete a node.";
                cout<<"\n4. Display Inorder traversal of the tree.";
                cout<<"\n5. Display Preorder traversal of the tree.";
                cout<<"\n6. Exit.";
                cout<<"\nEnter your choice: ";
                cin>>choice;
                switch(choice)
                {
                        case 1:
                        	 cout<<"\nEnter data to insert: ";
                        	 int ndata;
                        	 cin>>ndata;
                                avltree.root=avltree.insert(avltree.root, ndata);
                                continue;
                       
                        case 2:
                                avltree.search();
                                continue;
                       
                        case 3:
                        	 cout<<"\nEnter data to delete: ";
                        	 int key;
                        	 cin>>key;
                                avltree.root=avltree.delnode(avltree.root, key);
                                continue;
                       
                        case 4:
                                avltree.inorder_traversal();
                                continue;
                                
                        case 5:
                                avltree.preorder_traversal();
                                continue;
                       
                        case 6:
                                cout<<"\nThank you!\n";
                                exit(0);
                       
                        default:
                                cout<<"\nInvalid choice.\n";
                }
        }
        return 0;
}
