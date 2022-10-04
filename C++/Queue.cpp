// Github username: dubey2709
// Aim: adding Queue Data Structure
// Date: 04/10/22

#include<iostream>
using namespace std;
#define size 5
int Queue[size];
int R=-1,F=-1;

void Enqueue(int x)
{
    if(R==size-1)
    {
        cout<<"Overflow"<<endl;
        exit(1);
    }
    else if(R==-1)
    {
        R=0;F=0;
        Queue[R]=x;
    }
    else
    {
        R=R+1;
        Queue[R]=x;
    }
}

void Dequeue()
{
    if(F==-1)
    {
        cout<<"Underflow"<<endl;
        exit(0);
    }
    else if(F==R)
    {
        int x=Queue[F];
        F=-1;R=-1;
    }
    else
    {
        int x= Queue[F];
        F++;
    }
}

int main()
{
    int c;
    while(1)
    {
        cout<<"\nWhat operation do you want to perform : \n1. Insertion \n2. Deletion \n3. Display \n4. Exit \n"<<endl;
        cout<<"Enter your input : ";
        cin>>c;
        switch(c)
        {
            case 1:
            {
                int x;
                cout<<"Enter the element you want to insert : ";
                cin>>x;
                Enqueue(x);
                break;
            }

            case 2:
            {
                Dequeue();
                break;
            }

            case 3:
            {
                cout<<"\nElements in Queue : ";
                for(int i=F;i<=R;i++)
                {
                    cout<<Queue[i]<<" ";
                }
                cout<<"\n";
                break;
            }

            case 4:
            {
                exit(0);
                break;
            }
        }
    }
    return 0;
}