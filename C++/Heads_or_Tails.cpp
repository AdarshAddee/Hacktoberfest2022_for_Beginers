// Github username: leslievelderrainx
// Aim: This program will randomly give you heads or tails 10 times
// Data: 10/21/22

#include<iostream>
#include<ctime>
using namespace std; 

int main () {
    srand(time(0)); 
    cout << time(0) << endl; 
    int coin;
    for (int i = 0; i < 10; i++) {
    coin = rand()%10; 
    if (coin <= 4) {
        cout << "Heads" << endl; 
    } else {
        cout << "Tails" << endl; 
    }
  }
  return 0; 
}