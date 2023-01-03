//SYCOD214
#include<iostream>
using namespace std;

class Employee
{
        public:
                string name;
                int id;
                int salary;
                friend void merge_sort(Employee *, int, int);
                friend void merge(Employee *, int, int, int);
};

const int maxsize=10;
Employee sorted[maxsize];

void merge_sort(Employee *emp, int lowb, int uppb)
{
        int mid;
        if(lowb<uppb)
        {
                mid=(lowb+uppb)/2;
                merge_sort(emp, lowb, mid);
                merge_sort(emp, mid+1, uppb);
                merge(emp, lowb, mid, uppb);
        }
}

void merge(Employee *emp, int lowb, int mid, int uppb)
{
        int i=lowb, j=mid+1, k=lowb;
        while(i<=mid && j<=uppb)
        {
                if(emp[i].salary>=emp[j].salary)
                {
                        sorted[k]=emp[i];
                        ++k;
                        ++i;
                }
                else
                {
                        sorted[k]=emp[j];
                        ++k;
                        ++j;
                }
        }
        if(i>mid)
        {
                while(j<=uppb)
                {
                        sorted[k]=emp[j];
                        ++k;
                        ++j;
                }
        }
        else if(j>uppb)
        {
                while(i<=mid)
                {
                        sorted[k]=emp[i];
                        ++k;
                        ++i;
                }
        }
        for(int i=lowb; i<=uppb; ++i)
                emp[i]=sorted[i];
}

int main()
{
        int size;
        cout<<"\nEnter the number of entries: ";
        cin>>size;
        Employee emp[size];
        for(int i=0;i<size;++i)
        {
                cout<<"\nEnter ID: ";
                cin>>emp[i].id;
                cout<<"\nEnter name: ";
                cin>>emp[i].name;
                cout<<"\nEnter salary: ";
                cin>>emp[i].salary;
        }
        int lowb=0, uppb=size-1;
        merge_sort(emp, lowb, uppb);
        cout<<"\nThe top 5 employees having highest salary are:\n";
        for(int i=0;i<5;++i)
        {
                cout<<"\nID: "<<sorted[i].id;
                cout<<"\nName: "<<sorted[i].name;
                cout<<"\nSalary: "<<sorted[i].salary<<" Rupees";
                cout<<endl;
        }
        return 0;
}
