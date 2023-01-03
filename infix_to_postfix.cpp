//SYCOD214
#include<iostream>
#include<string>
using namespace std;

class Stack
{
    public:
        char data;
        Stack * next;
};

class Stackop
{
    Stack *top;
    int maxsize=50;
    int size;
    public:
        void push(char);
        char pop();
        bool empty();
        bool full();
        char gettop();
        Stackop()
        {
            top=NULL;
            size=-1;
        }
};

bool Stackop::empty()
{
    if(top==NULL)
        return true;
    else
        return false;
}

bool Stackop::full()
{
    if(size==maxsize-1)
        return true;
    else
        return false;
}

void Stackop::push(char ele)
{
    Stack *newnode;
    newnode=new Stack;
    newnode->data=ele;
    if(top==NULL)
        newnode->next=top;
    else
        newnode->next=top;
    top=newnode;
    ++size;
}

char Stackop::pop()
{
    char popped;
    popped=top->data;
    top=top->next;
    --size;
    return popped;
}

char Stackop::gettop()
{
    if(!empty())
        return(top->data);
    else
        return '!';
}

int priority_check(char oprtr)
{
    int ret;
    switch(oprtr)
    {
        case '^':
            ret=3;
            break;
       
        case '*':
            ret=2;
            break;
       
        case '/':
            ret=2;
            break;
       
        case '+':
            ret=1;
            break;
       
        case '-':
            ret=1;
            break;
       
        default:
            ret=0;
    }
    return ret;
}

int main()
{
    Stackop sta;
    string infixex;
    int len=0;
    int index1=0, index2=0, icppri, isppri;
    char icp, isp, popped;
    cout<<"\nEnter an infix expression: ";
    getline(cin, infixex);
    for(auto ch:infixex)
        ++len;
    char postfixex[len];
    infixex=infixex+"#";
    icp=infixex[index1];
    while(icp!='#')
    {
        if(icp=='(')
        {
            sta.push(icp);
            while(icp!=')')
            {
                icppri=priority_check(icp);
                isp=sta.gettop();
                isppri=priority_check(isp);
                if(icppri==0 && icp!='!')
                    postfixex[index2++]=icp;
                else if(icppri>isppri)
                    sta.push(icp);
                else if(icppri<=isppri)
                {
                    popped=sta.pop();
                    postfixex[index2++]=popped;
                    sta.push(icp);
                }
                icp=infixex[++index1];
            }
            while(sta.gettop()!='(')
            {
                popped=sta.pop();
                postfixex[index2++]=popped;
            }
            popped=sta.pop();
        }
        else
        {
            icppri=priority_check(icp);
            isp=sta.gettop();
            isppri=priority_check(isp);
            if(sta.empty() && icppri==0)
                postfixex[index2++]=icp;
            else if(icppri==0 && icp!='!')
                postfixex[index2++]=icp;
            else if(icppri>isppri)
                sta.push(icp);
            else if(icppri<=isppri)
            {
                popped=sta.pop();
                sta.push(icp);
                postfixex[index2++]=popped;
            }
        }
        icp=infixex[++index1];
    }
    while(!sta.empty())
    {
        popped=sta.pop();
        postfixex[index2++]=popped;
    }
    postfixex[index2]='#';
    cout<<"\nThe postfix expression is: ";
    for(auto ch:postfixex)
        if(ch!='('&&ch!='#')
            cout<<ch;
    cout<<endl;
    return 0;
}
