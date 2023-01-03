//SYCOD214
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Graph
{
        public:
                int data;
                int cost;
                bool visited;
                Graph *next;
                Graph()
                {
                	data=0;
                	cost=0;
                	visited=0;
                	next=NULL;
                }
};

class Graphop
{
        int size;
        int total_cost;
        Graph * adjlst[10];
        public:
                Graph * getnode();
                void create();
                void prim_mst();
                Graphop()
                {
                	for(int i=0;i<10;++i)
                	{
		        	Graph *newnode;
		        	newnode=new Graph;
                		adjlst[i]=newnode;
                	}
                	total_cost=0;
                }
};

Graph * Graphop::getnode()
{
	Graph *newnode;
	newnode=new Graph;
	do
	{
		cout<<"\nEnter node data: ";
		cin>>newnode->data;
		if(!((newnode->data)>0 && (newnode->data)<=size))
		{
			cout<<"\nInvalid data! Please try again.";
			continue;
		}
		cout<<"\nEnter cost (edge-weight): ";
		cin>>newnode->cost;
		break;
	}while(1);
	return newnode;
}

void Graphop::create()
{
        cout<<"\nEnter number of elements: ";
        cin>>size;
        for(int i=1;i<=size;++i)
        {
        	adjlst[i-1]->data=i;
        	int sizecon;
        	cout<<"\nEnter the number of nodes connected to node "<<i<<": ";
        	cin>>sizecon;
        	Graph *temp=adjlst[i-1];
        	for(int j=0;j<sizecon;++j)
        	{
        		Graph *newnode=getnode();
        		temp->next=newnode;
        		temp=newnode;
        	}
        }
}

void Graphop::prim_mst()
{
	cout<<"\nOrder of nodes of the minimum spanning tree using Prim's algorithm is: ";
	vector <int> primlst;
	primlst.push_back(adjlst[0]->data);
	for(int i=0;i<size-1;++i)
	{
		int min=999;
		Graph * nextdata;
		int tempele;
		for(int j=0;j<size;++j)
		{
			for(auto ele:primlst)
			{
				if(ele==adjlst[j]->data)
				{
					Graph *temp=(adjlst[j])->next;
					while(temp!=NULL)
					{
						if(temp->visited!=1 && (find(primlst.begin(), primlst.end(), temp->data)==primlst.end()))
							if(min>temp->cost)
							{
								min=temp->cost;
								nextdata=temp;
								tempele=ele;
							}
						temp=temp->next;
					}
				}
			}
		}
		nextdata->visited=1;
		total_cost+=nextdata->cost;
		primlst.push_back(nextdata->data);
		for(int j=0;j<size;++j)
		{
			if((adjlst[j])->data==(nextdata->data))
			{
				Graph *temp=(adjlst[j])->next;
				while(temp!=NULL)
				{
					if(temp->data==tempele)
					{
						temp->visited=1;
						break;
					}
					temp=temp->next;
				}
				break;
			}
		}	
	}
	for(auto ele:primlst)
		cout<<ele<<" ";
	cout<<"\nThe total cost of the minimum spanning tree is: "<<total_cost;
	cout<<endl;
}

int main()
{
	Graphop mst;
	mst.create();
	mst.prim_mst();
	return 0;
}
