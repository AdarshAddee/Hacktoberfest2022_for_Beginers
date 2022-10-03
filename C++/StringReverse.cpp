#include <iostream>
using namespace std;

void reverse(string& str, int i, int j){

    if(i > j)
        return;

    swap(str[i++],str[j--]);
    reverse(str,i,j);
}   

int main(){

    string str;
    cin >> str;

    cout << "Normal string is - " << str << endl;

    reverse(str, 0, str.length()-1);

    cout << "The reverse string is - " << str << endl;

}
