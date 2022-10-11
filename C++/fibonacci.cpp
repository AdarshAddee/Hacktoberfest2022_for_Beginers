#include<iostream> //Preprocessor Directive
using namespace std;
int fibonacci(int n) //Making a function for fibonacci series
{ if(n<=1)
return n;
return fibonacci(n-1)+fibonacci(n-2);
}
int main()  //Main Function
{ int a;
cout<<"Enter number of terms you want in fibonacci: ";
cin>>a;
cout<<"The fibonacci series is:"<<endl;
for(int i=0;i<a;i++)
{ cout<<fibonacci(i)<<",";
}
return 0;
}