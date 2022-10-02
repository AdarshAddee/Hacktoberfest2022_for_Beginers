// A  color game made by Aditya khattri. github:adityakhattri21
#include <iostream>
#include <windows.h>
#include <vector>
#include <conio.h>
#include <time.h>
#include <dos.h>

using namespace std;

void display();
void game();


void display(){
    cout<<"#######################################################"<<endl;
    cout<<"#           Welcome to the Color Game                 #"<<endl;
    cout<<"#                                                     #"<<endl;
    cout<<"#                    Rule :                           #"<<endl;
    cout<<"#           Enter the color of the word               #"<<endl;
    cout<<"#                                                     #"<<endl;
    cout<<"#######################################################"<<endl;
    cout<<endl;
    cout<<"Press any key to continue: ";
    getch();
}

void game(){
    int score =0;
    string ans;
    int flag=0;
     vector <string> word_color {"Blue","Green","Yellow","Orange","Red","Brown","Black","Purple"};
     vector <int> color_id {1,2,4,5,6,9};
     do{
     system("cls");
     srand(time(0));
     int s=rand() % color_id.size();
     switch(s){
         case 1 :
         {
             system("Color 71");
             srand(time(0));
             int  t=rand() % word_color.size();
             cout<<word_color.at(t)<<endl;
             break;
         }
         case 2 :
         {
             system("Color 72");
             srand(time(0));
             int t=rand() % word_color.size();
             cout<<word_color.at(t)<<endl;
             break;
         }
         case 4 :
         {
             system("Color 74");
             srand(time(0));
             int t=rand() % word_color.size();
             cout<<word_color.at(t)<<endl;
             break;
         }
         case 5 :
         {
             system("Color 75");
             srand(time(0));
             int t=rand() % word_color.size();
             cout<< word_color.at(t)<<endl;
             break;
         }
         case 6 :
         {
             system("Color 76");
             srand(time(0));
             int t=rand() % word_color.size();
             cout<<word_color.at(t)<<endl;
             break;
         }
          case 9 :
         {
             system("Color 79");
             srand(time(0));
             int t=rand() % word_color.size();
             cout<<word_color.at(t)<<endl;
             break;
         }
         default:{
             goto START;
//             system("Color 70");
//             srand(time(0));
//             int t=rand() % word_color.size();
//             cout<<word_color.at(t)<<endl;
             
         }
     }
     cout<<"Enter Your Answer:";
     cin>>ans;
     if(ans == "blue" && s==1){
         score++;
         flag=1;
     }
     else if(ans == "green" && s==2){
         score++;
         flag=1;
     }
     else if(ans == "red" && s==4){
         score++;
         flag=1;
     }
     else if(ans == "purple" && s==5){
         score++;
         flag=1;
     }
     else if(ans == "yellow" && s==6){
         score++;
         flag=1;
     }
     else {
         flag=0;
     }
     START:
     continue;
     
    }while(flag);
    cout<<"Game Over Your Score is : "<<score<<endl;
}


int main(){
    display();
    system("cls");
    game();
    
    cout<<endl;
    return 0;
}





