//SYCOD214
#include<iostream>
using namespace std;

class Graph
{
	public:
		int data;
		bool visiteddfs;
		bool visitedbfs;
		Graph *next;
		Graph *nextst;
		Graph *nextqu;
		Graph()
		{
			visiteddfs=false;
			visitedbfs=false;
			next=NULL;
			nextst=NULL;
			nextqu=NULL;
		}
};

class Graphop
{
	Graph * adjlst[10];
	public:
		int size;
		Graph * getnode();
		void create();
		void depth_first_search();
		void breadth_first_search();
		Graphop()
		{
			for(int i=0;i<10;++i)
			{
				Graph * newnode;
				newnode=new Graph;
				adjlst[i]=newnode;
			}
		}
};

class Stackop
{
	Graph * top;
	public:
		int stsize;
		bool empty();
		void push(Graph *);
		Graph * pop();
		Stackop()
		{
			top=NULL;
			stsize=0;
		}
};

bool Stackop::empty()
{
	if(top==NULL)
		return true;
	else
		return false;
}

void Stackop::push(Graph * value)
{
	Graph *newnode=new Graph;
	newnode=value;
	if(empty())
		newnode->nextst=NULL;
	else
		newnode->nextst=top;
	top=newnode;
	++stsize;
}

Graph * Stackop::pop()
{
	Graph *value;
	if(empty())
	{
		value->data=-1;
		value->nextst=NULL;
	}
	else
	{
		value=top;
		top=top->nextst;
	}
	return value;
}

class Queueop
{
	Graph *front, *rear;
	public:
		int qusize;
		bool empty();
		void insert(Graph *);
		Graph * delele();
		Queueop()
		{
			front=NULL;
			rear=NULL;
			qusize=0;
		}
};

bool Queueop::empty()
{
	if(front==NULL)
		return true;
	else
		return false;
}

void Queueop::insert(Graph * value)
{
	Graph *newnode=new Graph;
	newnode=value;
	if(empty())
		front=newnode;
	else
		rear->nextqu=newnode;
	newnode->nextqu=NULL;
	rear=newnode;
	++qusize;
}

Graph * Queueop::delele()
{
	Graph *value;
	if(empty())
	{
		value->data=-1;
		value->nextqu=NULL;
	}
	else
	{
		value=front;
		front=front->nextqu;
	}
	return value;
}

Graph * Graphop::getnode()
{
	Graph *newnode;
	newnode=new Graph;
	bool pass=false;
	while(!pass)
	{
		cout<<"\nEnter data: ";
		cin>>newnode->data;
		if((newnode->data)>0 && (newnode->data)<=size)
			pass=true;
		else
			cout<<"\nValue out of range. Please try again.\n";
	}
	return newnode;
}

void Graphop::create()
{
	cout<<"\nEnter number of nodes: ";
	cin>>size;
	int conn;
	for(int i=0;i<size;++i)
	{
		adjlst[i]->data=i+1;
		cout<<"\nEnter number of nodes connected to node "<<i+1<<": ";
		cin>>conn;
		for(int j=0;j<conn;++j)
		{
			Graph *newnode=getnode(), *temp=adjlst[i];
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=newnode;
		}
	}
}

void Graphop::depth_first_search()
{
	cout<<"\nOrder of depth-first search is: ";
	Stackop stack;
	Graph *temp, *popped;
	temp=adjlst[0];
	stack.push(temp);
	int val;
	while(!stack.empty())
	{
		popped=stack.pop();
		val=popped->data;
		if(adjlst[val-1]->visiteddfs==false)
		{
			cout<<val<<"  ";
			temp=adjlst[val-1];
			for(int i=0;i<size;++i)
			{
				temp=adjlst[i];
				while(temp!=NULL)
				{
					if(temp->data==val)
						temp->visiteddfs=true;
					temp=temp->next;
				}
			}
			temp=adjlst[val-1]->next;
			while(temp!=NULL)
			{
				stack.push(temp);
				temp=temp->next;
			}
		}
	}
	cout<<endl;
}

void Graphop::breadth_first_search()
{
	cout<<"\nOrder of breadth-first search is: ";
	Queueop queue;
	Graph *temp, *popped;
	temp=adjlst[0];
	queue.insert(temp);
	int val=adjlst[0]->data;
	for(int i=0;i<size;++i)
	{
		temp=adjlst[i];
		while(temp!=NULL)
		{
			if(temp->data==val)
				temp->visitedbfs=true;
			temp=temp->next;
		}
	}
	while(queue.qusize!=size)
	{
		popped=queue.delele();
		cout<<popped->data<<"  ";
		temp=adjlst[(popped->data)-1]->next;
		Graph *temp1;
		while(temp!=NULL)
		{
			if(temp->visitedbfs==false)
			{
				val=temp->data;
				queue.insert(temp);
				for(int i=0;i<size;++i)
				{
					temp1=adjlst[i];
					while(temp1!=NULL)
					{
						if(temp1->data==val)
							temp1->visitedbfs=true;
						temp1=temp1->next;
					}
				}
			}
			temp=temp->next;
		}
	}
	while(!queue.empty())
	{
		popped=queue.delele();
		cout<<popped->data<<"  ";
	}
	cout<<endl;
}

int main()
{
	Graphop graph;
	graph.create();
	graph.depth_first_search();
	graph.breadth_first_search();
	return 0;
}
