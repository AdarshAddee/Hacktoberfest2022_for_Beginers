// AdrshCode

#include <iostream>
using namespace std;
int main() {
  int row = 4, column = 4;
  for (int i = 1; i <= row ; i++){
    for (int j = 1; j <= column ; j++)
      cout << " * ";
    cout << endl;
  }
  return 0;
}

//The same above code can be made more readable and user friendly by adding a few lines
//Following is the code with those additional lines:

/*#include <iostream>
using namespace std;
int main() {
	
  int row, column;
  
  cout<<"Enter number of Rows: ";
  cin>>row;
  cout<<"Enter number of Columns: ";
  cin>>column;
  
  for (int i = 1; i <= row ; i++){
    for (int j = 1; j <= column ; j++)
      cout << " * ";
    cout << endl;
  }
  return 0;
}*/

