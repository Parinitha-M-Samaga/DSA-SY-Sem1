//SYCOD214
#include <iostream>
using namespace std;

class Stack
{
	public:
		int data;
		Stack * next;
};

class Stacknew
{
	Stack *top;
	int maximum=5;
	int size;
	public:
		void push(int ele);
		int pop();
		int gettop();
		bool empty();
		bool full();
		int currsize();
		void display();
		Stacknew()
		{
			top=NULL;
			size=-1;
		}
};

bool Stacknew::full()
{
	if(size==(maximum-1))
		return true;
	else
		return false;
}

bool Stacknew::empty()
{
	if(size==-1)
		return true;
	else
		return false;
}

void Stacknew::push(int ele)
{
	if(!full())
	{
		Stack * newnode;
		newnode=new Stack;
		newnode->data=ele;
		if(size==-1)
			newnode->next=NULL;
		else
			newnode->next=top;
		top=newnode;
		++size;
	}
	else
		cout<<"\nStack Overflow!\n";
}

int Stacknew::pop()
{
	int popped;
	if(!empty())
	{
		Stack *temp=top;
		popped=top->data;
		top=top->next;
		delete temp;
		--size;
	}
	else
		popped=-1;
	return popped;
}

int Stacknew::gettop()
{
	int ret;
	if(top==NULL)
		ret=-1;
	else
		ret=top->data;
	return (ret);
}

int Stacknew::currsize()
{
	return (size+1);
}

void Stacknew::display()
{
	Stack *temp=top;
	if(top==NULL)
		cout<<"\nStack Underflow!\n";
	else
	{
		cout<<"\nTop: "<<top->data<<endl;
		while(temp!=NULL)
		{
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<"NULL\n";
	}
}

int main()
{
	Stacknew s;
	int ch, ele;
	while(1)
	{
		cout<<"\nMenu:";
		cout<<"\n1. Push an element.";
		cout<<"\n2. Pop the first element.";
		cout<<"\n3. Display the stack.";
		cout<<"\n4. Get the topmost element.";
		cout<<"\n5. Get the current size.";
		cout<<"\n6. Exit";
		cout<<"\nEnter choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				cout<<"\nEnter data: ";
				cin>>ele;
				s.push(ele);
				s.display();
				continue;
			}
		    
			case 2:
			{
				int popped=s.pop();
				if(popped==-1)
					cout<<"\nStack Underflow!\n";
				else
				{
					cout<<"\nPopped element: "<<popped<<endl;
					s.display();
				}
				continue;
			}
		    
			case 3:
				s.display();
				continue;
		    
			case 4:
			{
				int get=s.gettop();
				if(get==-1)
					cout<<"\nStack Underflow!\n";
				else
					cout<<"\nElement at the top is: "<<get<<endl;
				continue;
			}
		    
			case 5:
				cout<<"\nStack size is: "<<s.currsize()<<endl;
				continue;
		    
			case 6:
				return 0;
		    
			default:
				cout<<"\nInvalid choice.\n";
		}
	}
	return 0;
}
