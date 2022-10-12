#this a another type of pattern  questions.
#A 
#B C 
#C D E 
#D E F G 


#include<iostream>
using namespace std ;

int main(){

    int n;
    cin>>n;

    int row = 1;
    while(row<=n){
        int col = 1;
        while(col<=row){
         

         char st = 'A' + row + col  - 2;
            cout<<st << " " ;

            
            col= col + 1;

        }

        cout<<endl;
        row = row + 1;
    }


}
