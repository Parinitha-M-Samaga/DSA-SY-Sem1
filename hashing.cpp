//SYCOD214
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

const int size=7;

class Employee
{
    private:
        struct emp
        {
            string ename;
            string cname;
            long int empl_id;
        } tel[size];
    public:
        Employee()
        {
            for(int i=0;i<size;++i)
            {
                tel[i].ename="_";
                tel[i].cname="_";
                tel[i].empl_id=0;
            }
        }
        void linear_collision(long int, string, string, long int);
        void quadratic_collision(long int, string, string, long int);
        void double_hashing(long int, string, string, long int);
        void insert();
        void display();
        long int search(long int);
        void entdelete();
};

long int hash_fun(long int numb)
{
    return(numb%size);
}

long int hash_fun2(long int numb)
{
    long int key;
    key=((5*numb)+2)%size;
    return(key);
}

void Employee::linear_collision(long int loc, string name, string comp, long int numb)
{
    long int loctemp;
    for(int i=0;i<size;++i)
    {
        loctemp=(loc+i)%size;
        if(tel[loctemp].empl_id==0)
        {
            tel[loctemp].ename=name;
            tel[loctemp].cname=comp;
            tel[loctemp].empl_id=numb;
            cout<<"\n"<<loctemp;
            break;
        }
        else
            loctemp=loc;
    }
}

void Employee::quadratic_collision(long int loc, string name, string comp, long int numb)
{
    long int loctemp;
    for(int i=0;i<size;++i)
    {
        loctemp=(loc+(i*i))%size;
        if(tel[loctemp].empl_id==0)
        {
            tel[loctemp].ename=name;
            tel[loctemp].cname=comp;
            tel[loctemp].empl_id=numb;
            cout<<"\n"<<loctemp;
            break;
        }
        else
            loctemp=loc;
    }
}

void Employee::double_hashing(long int loc, string name, string comp, long int numb)
{
    long int loctemp, loc2;
    loc2=hash_fun2(numb);
    for(int i=0;i<size;++i)
    {
        loctemp=(loc+(loc2*i))%size;
        if(tel[loctemp].empl_id==0)
        {
            tel[loctemp].ename=name;
            tel[loctemp].cname=comp;
            tel[loctemp].empl_id=numb;
            cout<<"\n"<<loctemp;
            break;
        }
        else
            loctemp=loc;
    }
}

void Employee::insert()
{
    string name;
    string comp;
    long int numb;
    int ch, flag=0;
    for(int i=0;i<size;++i)
    {
        long int numb, loc;
        cout<<"\nEnter the name of the employee: ";
        cin>>name;
        cout<<"\nEnter the name of the company: ";
        cin>>comp;
        cout<<"\nEnter the Employee ID: ";
        cin>>numb;
        loc=hash_fun(numb);
        if(tel[loc].empl_id==0)
        {
            tel[loc].ename=name;
            tel[loc].cname=comp;
            tel[loc].empl_id=numb;
            cout<<"\n"<<loc;
        }
        else
        {
            flag=0;
            while(1)
            {
		    if(flag==1)
		    	break;
		    cout<<"\nCollision at loctaion "<<loc<<".\n";
		    cout<<"\nWhich collision method do you prefer?";
		    cout<<"\n1. Linear probing.";
		    cout<<"\n2. Quadratic probing.";
		    cout<<"\n3. Double hashing.";
		    cout<<"\nEnter your choice: ";
		    cin>>ch;
		    switch(ch)
		    {
			    case 1:
				linear_collision(loc,name,comp,numb);
				flag=1;
				break;
				
			    case 2:
				quadratic_collision(loc,name,comp,numb);
				flag=1;
				break;
				
			    case 3:
			    	double_hashing(loc,name,comp,numb);
			    	flag=1;
			    	break;
			    	
			    default:
			    	cout<<"\nInvalid choice.\n";
		    }
            }
        }
    }
}

void Employee::display()
{
    cout<<endl<<"Employee details:\n";
    cout<<"Sr. No."<<setw(15)<<"Employee name"<<setw(15)<<"Company name"<<setw(17)<<"Employee ID"<<endl;
    for(int i=0;i<size;++i)
    {
        cout<<(i+1)<<setw(15)<<tel[i].ename<<setw(15)<<tel[i].cname<<setw(23)<<tel[i].empl_id<<endl;
        cout<<endl;
    }
}

long int Employee::search(long int numb)
{
    long int loc, loctemp;
    int flag=0;
    loc=hash_fun(numb);
    if(tel[loc].empl_id!=numb)
    {
        for(int i=0;i<size;++i)
        {
            loctemp=(loc+i)%size;
            if(tel[loctemp].empl_id==numb)
            {
                flag=1;
                break;
            }
            else
                loctemp=loc;
        }
    }
    else
    {
    	loctemp=loc;
    	flag=1;
    }
    if(flag==1)
        return loctemp;
    else
        return -1;
}

void Employee::entdelete()
{
    long int numb;
    cout<<"\nEnter the Employee ID: ";
    cin>>numb;
    long int loc=search(numb);
    if(loc!=-1)
    {
        tel[loc].ename="_";
        tel[loc].cname="_";
        tel[loc].empl_id=0;
        cout<<"\nEntry successfully deleted.\n";
    }
    else
    	cout<<endl<<"Entry not found!\n";
}

int main()
{
    int ch;
    long int loc;
    Employee obj;
    obj.insert();
    while(1)
    {
	    cout<<"\nMenu:";
	    cout<<"\n1. Display all entries.";
	    cout<<"\n2. Search for an entry.";
	    cout<<"\n3. Delete an entry.";
	    cout<<"\n4. Exit";
	    cout<<"\nEnter your choice: ";
	    cin>>ch;
	    switch(ch)
	    {
	    	case 1:
	    	    obj.display();
	    	    continue;
	    	
	    	case 2:
	    	{
	    	    long int cont;
	    	    cout<<"\nEnter the Employee ID: ";
	    	    cin>>cont;
	    	    loc=obj.search(cont);
	    	    if(loc!=-1)
	    	    	cout<<"\nThe entry is stored in serial number: "<<(loc+1)<<endl;
	    	    else
	    	    	cout<<"\nEntry not found!\n";
	    	    continue;
	    	}
	    	
	    	case 3:
	    	    obj.entdelete();
	    	    continue;
	    	
	    	case 4:
	    	    return 0;
	    	
	    	default:
	    	    cout<<"\nPlease enter a valid choice.\n";
	    }
    }
    return 0;
}
