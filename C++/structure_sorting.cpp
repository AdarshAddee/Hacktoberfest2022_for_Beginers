#include <iostream>
#include<algorithm>
using namespace std;
struct book {
   string title;
   int pages;
   float price;
};
bool compareBook(book b1, book b2) {
   if(b1.price < b2.price) {
      return true;
   } return false;
}
main() {
   book book_arr[5];
   book_arr[0].title = "C Programming";
   book_arr[0].pages = 260;
   book_arr[0].price = 450;
   book_arr[1].title = "DBMS Guide";
   book_arr[1].pages = 850;
   book_arr[1].price = 775;
   book_arr[2].title = "Learn C++";
   book_arr[2].pages = 350;
   book_arr[2].price = 520;
   book_arr[3].title = "Data Structures";
   book_arr[3].pages = 380;
   book_arr[3].price = 430;
   book_arr[4].title = "Learn Python";
   book_arr[4].pages = 500;
   book_arr[4].price = 300;
   sort(book_arr, book_arr + 5, compareBook);
   for(int i = 0; i<5; i++) {
      cout << book_arr[i].title << "\t\t" << book_arr[i].pages << "\t\t" <<
         book_arr[i].price << endl;
   }
}
