//SYCOD214
#include <iostream>
using namespace std;

class Tnode
{
        public:
                int data;
                Tnode *lchild;
                Tnode *rchild;
                Tnode *next;     //For stack
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
        Tnode *root;
        public:
                Tnode* getnode();
                void insert();
                void inorder_traversal();
                void preorder_traversal();
                void postorder_traversal();
                void search();
                void delnode();
                Tnop()
                {
                        root=NULL;
                }
};

Tnode* Tnop::getnode()
{
        Tnode *newnode;
        newnode=new Tnode;
        cout<<"\nEnter value of the node: ";
        cin>>newnode->data;
        newnode->lchild=NULL;
        newnode->rchild=NULL;
        newnode->next=NULL;
        return newnode;
}

void Tnop::insert()
{
        Tnode *newnode;
        newnode=getnode();
        if(root==NULL)
                root=newnode;
        else
        {
                Tnode *temp=root;
                while(temp!=NULL)
                {
                        if((newnode->data)==(temp->data))
                        {
                                cout<<"\nRedundant data!\n";
                                break;
                        }
                        else if((newnode->data)<(temp->data))
                        {
                                if(temp->lchild==NULL)
                                {
                                        temp->lchild=newnode;
                                        break;
                                }
                                else
                                        temp=temp->lchild;
                        }
                        else if((newnode->data)>(temp->data))
                        {
                                if(temp->rchild==NULL)
                                {
                                        temp->rchild=newnode;
                                        break;
                                }
                                else
                                        temp=temp->rchild;
                        }
                }
        }
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

void Tnop::delnode()
{
        if(root==NULL)
        {
                cout<<"\nTree is empty!\n";
                return;
        }
        int value, flag=0;
        Tnode *temp=root, *parent=root;
        cout<<"\nEnter value to delete: ";
        cin>>value;
        while(temp!=NULL)
        {
                if(value==(temp->data))
                {
                        flag=1;
                        break;
                }
                else if(value<(temp->data))
                {
                        parent=temp;
                        temp=temp->lchild;
                }
                else if(value>(temp->data))
                {
                        parent=temp;
                        temp=temp->rchild;
                }
        }
        if(flag==1)
        {
                if(temp->lchild==NULL && temp->rchild==NULL)
                {
                        cout<<endl<<value<<" is a leaf node.\n";
                        if(temp!=root)
                        {
                                if(parent->lchild==temp)
                                        parent->lchild=NULL;
                                else
                                        parent->rchild=NULL;
                        }
                        else
                                root=NULL;
                }
                else if(temp->lchild!=NULL && temp->rchild==NULL)
                {
                        cout<<endl<<value<<" has left child only.\n";
                        if(temp!=root)
                        {
                                if(parent->lchild==temp)
                                        parent->lchild=temp->lchild;
                                else
                                        parent->rchild=temp->lchild;
                        }
                        else
                                root=root->lchild;
                }
                else if(temp->rchild!=NULL && temp->lchild==NULL)
                {
                        cout<<endl<<value<<" has right child only.\n";
                        if(temp!=root)
                        {
                                if(parent->lchild==temp)
                                        parent->lchild=temp->rchild;
                                else
                                        parent->rchild=temp->rchild;
                        }
                        else
                                root=root->rchild;
                }
                else
                {
                        cout<<endl<<value<<" has both left child and right child.\n";
                        Tnode *temp1=temp->rchild;
                        while(temp1->lchild!=NULL)
                        temp1=temp1->lchild;
                        temp1->lchild=temp->lchild;
                        if(parent->rchild==temp)
                        parent->rchild=temp->rchild;
                        else
                        parent->lchild=temp->rchild;
                        if(temp==root)
                        root=root->rchild;
                }
                delete temp;
        }
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

void Tnop::postorder_traversal()
{
        if(root==NULL)
        {
                cout<<"\nTree is empty!\n";
                return;
        }
        cout<<"\nThe postorder traversal is:  ";
        Stackop stack1, stack2;
        Tnode *temp=root;
        stack1.push(temp);
        while(!stack1.empty())
        {
                temp=stack1.pop();
                if(temp->lchild)
                        stack1.push(temp->lchild);
                if(temp->rchild)
                        stack1.push(temp->rchild);
                stack2.push(temp);
        }
        while(!stack2.empty())
        {
                temp=stack2.pop();
                cout<<temp->data<<"  ";
        }
        cout<<endl;
}

int main()
{
        Tnop tree;
        int choice;
        while(1)
        {
                cout<<"\nMenu:";
                cout<<"\n1. Insert a node.";
                cout<<"\n2. Search for a node.";
                cout<<"\n3. Delete a node.";
                cout<<"\n4. Display Inorder traversal of the tree.";
                cout<<"\n5. Display Preorder traversal of the tree.";
                cout<<"\n6. Display Postorder traversal of the tree.";
                cout<<"\n7. Exit.";
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
                                tree.delnode();
                                continue;
                       
                        case 4:
                                tree.inorder_traversal();
                                continue;
                       
                        case 5:
                                tree.preorder_traversal();
                                continue;
                       
                        case 6:
                                tree.postorder_traversal();
                                continue;
                       
                        case 7:
                                cout<<"\nThank you!\n";
                                exit(0);
                       
                        default:
                                cout<<"\nInvalid choice.\n";
                }
        }
        return 0;
}
