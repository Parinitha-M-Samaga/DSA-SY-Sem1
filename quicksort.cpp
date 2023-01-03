//SYCOD214
#include<iostream>
using namespace std;

class Employee
{
        public:
                int id;
                string name;
                int salary;
                friend void quick_sort(Employee *, int, int);
                friend int partition(Employee *, int, int);
};

// const int maxsize=10;
// Employee sorted[maxsize];

void swap(Employee *ele1, Employee *ele2)
{
        Employee temp;
        temp=*ele1;
        *ele1=*ele2;
        *ele2=temp;
}

void quick_sort(Employee *emp, int lowb, int uppb)
{
        int loc;
        if(lowb<uppb)
        {
                loc=partition(emp, lowb, uppb);
                quick_sort(emp, lowb, loc-1);
                quick_sort(emp, loc+1, uppb);
        }
}

int partition(Employee *emp, int lowb, int uppb)
{
        int pivot=emp[lowb].salary, start=lowb, end=uppb+1;
        while(start<end)
        {
                while(emp[start].salary>=pivot)
                        ++start;
                while(emp[end].salary<pivot)
                        --end;
                if(start<end)
                        swap(&emp[start], &emp[end]);
        }
        swap(&emp[lowb], &emp[end]);
        return end;
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
        quick_sort(emp, lowb, uppb);
        cout<<"\nThe top 5 employees having highest salary are:\n";
        for(int i=0;i<5;++i)
        {
                cout<<"\nID: "<<emp[i].id;
                cout<<"\nName: "<<emp[i].name;
                cout<<"\nSalary: "<<emp[i].salary<<" Rupees";
                cout<<endl;
        }
        return 0;
}
