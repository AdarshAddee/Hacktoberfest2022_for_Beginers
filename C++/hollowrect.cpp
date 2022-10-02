#include<bits/stdc++.h>
using namespace std;

int main(){

    int rows, cols;
    // Getting dimensions of rectangle
    cout << "Enter the number of rows in rectangle - ";
    cin >> rows;

    cout << "Enter the number of columns in rectangle - ";
    cin >> cols;


    cout << "Rectangle of dimensions " << rows << "*" << cols << endl;

    // Main logic to print hollow rectangle. 
    for( int i = 0; i < rows; i++ ) {
        for( int j = 0; j < cols; j++ ){

            // If the index is at the border, then 
            // print *. 
            if( i == 0 || i == rows - 1 || j == 0 || j == cols -1 )
                cout<<"* ";
            else 
                cout<<"  ";
        }
        cout<<endl;
    }

    return 0;
}
