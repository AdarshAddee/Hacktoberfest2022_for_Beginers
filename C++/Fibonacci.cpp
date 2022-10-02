#include <iostream>
using namespace std;

int main () {
     int i, N, primo=1, secondo=1, terzo;

     do {
	    cout<<"Quanti numeri vuoi inserire?: ";
	    cin>>N;
      } while (N<3);

     cout<<primo<<","<<secondo;

     for(i=2;i<N;i++){
          terzo=primo+secondo;
          primo=secondo;
          secondo=terzo;
          cout<<","<<terzo;
     }

    return 0;
}