#include<iostream>
int addnum(int ele1,int ele2)
{
    int sum;
    sum=ele1+ele2;
 
    return sum;
}
int main()
{
    int sum1;
    std::cout<<"Enter the 2 numbers"<<std::endl;
    int ele1,ele2;
    std::cin>>ele1;
    std::cin>>ele2;
    sum1=addnum(ele1,ele2);
     std::cout<<sum1<<std::endl;

}