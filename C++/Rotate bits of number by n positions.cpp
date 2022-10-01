#include<iostream>
#include<stack>
using namespace std;


//Implemented using Airthmetic Shift , sign bit is not changed
void printBinary(int no){
stack<int> s;
int siz =0;
while(no){
    siz++;
    if(no%2)
        s.push(1);
    else
        s.push(0);
    no>>=1;
}

for(int i=0;i<31-siz;i++)
    cout<<"0";

while(!s.empty()){
cout<<s.top(); s.pop();
    }
cout<<endl;
}

int rotateBits(int no,int n){
//Assuming Right rotation

    int x = (1<<n)-1; //Generates a pattern of the type 0000...1111 (last n are ones)

    int lastNDigits  = no&x;

    no = no>>n ;
    int totalBits = sizeof(int)*8;

    lastNDigits = lastNDigits<<(totalBits-n-1);

    no = no|lastNDigits;

    return no;

}


int main(){

int no,n;
cin>>no>>n;
int ans = rotateBits(no,n);
cout<<"The new no formed from "<<no<<" is "<<ans<<"by rotating by "<<n<<endl;
cout<<"Original : ";
printBinary(no);
cout<<"New      : ";
printBinary(ans);

return 0;
}
