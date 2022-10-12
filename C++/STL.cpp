#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

// int main(){

//     //*************ARRAY LIBRARY USE*************/
    
//      int basic[3]={1,2,3};
//      // it is the basic methdo to form ana array

//      array<int,4> a = {1,2,3,4};
//      /*this is the method of forming a static array
//      by using the array library . we don't  use this library much */

//      int size = a.size();
//      for(int i=0; i<size; i++){
//         cout<<a[i]<<endl;
//      }

//      cout<<"element at 2nd inndex is -> "<<a.at(2)<<endl;
//      /*arrayname.at() is used to access the elements in an array*/
     
//      cout<<"empty or not -> "<<a.empty()<<endl;
//      /* .empty() tells whether the array if full/not empty (gives 0)
//       and if empty(gives 0)*/
//      cout<<"first element "<<a.front()<<endl;
//      cout<<"last element "<<a.back()<<endl;


// }  







// int main(){

//     /******************VECTOR LIBRARY USE************/

//     vector<int> v;
//     vector<int> a(5,3);
//     /* here 5 is the size and 1 is the 
//     number with which all the elements are 
//     initialsed */
//     cout<<"size of a is "<<a.size()<<endl;
//     cout<<"capacity of a is "<<a.capacity()<<endl;
//     cout<<"print a "<<endl;
//     for(int i:a){
//         cout<<i<<" ";
//     }cout<<endl;


//     cout<<"size -> "<<v.capacity()<<endl;
//     /* .capacity tells us about the total capacity of the array
//     there is a difference between capacity and size
//     size - tells us about the occupied boxes
//     capacity - whereas capacity tells us about the total space available
//     and vector increases by doubling the capacity (2X) */

//     v.push_back(1);
//     cout<<"capacity -> "<<v.capacity()<<endl;
//     // .push_back( value ) is used to insert a value  into the array


//     v.push_back(1);
//     cout<<"capacity -> "<<v.capacity()<<endl;

//     v.push_back(3);
//     cout<<"capacity -> "<<v.capacity()<<endl;
//     cout<<"size -> "<<v.size()<<endl;

//     cout<<"elements at 2nd index is "<<v.at(2)<<endl;

//     cout<<"front "<<v.front()<<endl;
//     cout<<"back "<<v.back()<<endl;

//     cout<<"before pop "<<endl;
//     for (int i:v)
//     {
//         cout<<i<<" ";
//     }cout<<endl;

//     v.pop_back();
//     /* pop removes the element */



//     cout<<"after pop "<<endl;
//     for (int i:v)
//     {
//         cout<<i<<" ";
//     }cout<<endl;

//     cout<<"before clear size "<<v.size()<<endl;
//     v.clear();
//     cout<<"after clear  size "<<v.size()<<endl;
        
    

// }






// int main(){


//     /********************DEQUE library USE***************/

//     deque<int> d;

//     d.push_back(1);
//     /*push is used to innsert the value and 
//     back means from the end and front means 
//     from the begunning */
//     d.push_front(2); 


//     cout<<endl;
//     cout<<"print the element at first index "<<d.at(1)<<endl;
//     cout<<" front "<<d.front()<<endl;
//     cout<<" back "<<d.back()<<endl;
//     cout<<" empty or not "<<d.empty()<<endl;
    
//     cout<<" before erase "<<d.size()<<endl;


//     d.erase(d.begin(),d.begin()+2);
//     cout<<"after erase "<<d.size()<<endl;
    





// }




// int main(){

//   /***************LIST LIBRARY USE**************/


//   /* list is a doubly linked list i.e. it has 
//   two pointers one at the beginning and other at 
//   the end of the list . if we have to access any element
//   then we have to travel to it by traverse. we can't use 
//   .at() function in this  */

//   list<int> l;

//   list<int> n(5,100);
//   cout<<"printing n"<<endl;
//   for(int i:n){
//     cout<<i<<" ";
//   }cout<<endl;

//   l.push_back(1);
//   l.push_front(4);

//   for(int i:l){
//     cout<<i<<" ";
//   }cout<<endl;

//   l.erase(l.begin());
//   cout<<"after erase "<<endl;
//   for(int i:l){
//     cout<<i<<" ";
//   }



// }


// int main(){


//     /********************STACK LIBRARY USE*****************/

//     /* stack -> last in first out or first in last out */

//     stack<string> s;

//     s.push("hardik");//first in
//     s.push("sehgal");//second in
//     s.push("is softspoken");//third in

//     cout<<"top element is "<<s.top()<<endl;

//     s.pop();

//     cout<<"top element is "<<s.top()<<endl;
//     cout<<"size of stack is "<<s.size()<<endl;
//     cout<<"empty or not "<<s.empty()<<endl;


// }


// int main(){

//     /*******************QUEUE LIBRARY USE***************/

//     /* queue -> it is like a line , who is first gets the
//     food first like in the hostel mess */

//     queue<string> q;
    
//     q.push("hardik");
//     q.push("sehagl");
//     q.push("is soft spoken");

//     cout<<"first member is  "<<q.front()<<endl;

//     cout<<" size befor pop is "<<q.size()<<endl;
//     q.pop();
//     cout<<"the size after the pop is "<<q.size()<<endl;




// }


// int main(){


//     /************PRIORITY QUEUE USING QUEUE*************/

//     //max heap -> gives max number out in the  front
//     priority_queue<int> maxi;

//     //min heap -> givrs min number out in the front
//     priority_queue<int,vector<int> , greater<int> > mini;

//     maxi.push(1);
//     maxi.push(3);
//     maxi.push(4);
//     maxi.push(0);

//     cout<<"size -> "<<maxi.size()<<endl;
//     int n = maxi.size();
//     for(int i=0; i<n; i++){
//         cout<<maxi.top()<<" ";
//         maxi.pop();
//     }cout<<endl;

//     mini.push(1);
//     mini.push(7);
//     mini.push(0);
//     mini.push(5);
    
//     int m = mini.size();
//     for(int i=0;i<m;i++){
//         cout<<mini.top()<<" ";
//         mini.pop();
//     }cout<<endl;

// }



// int main(){


//     /***************SET LIBRARY USE**************/

//     set<int> s;
//     /* in set no value can be repeated i.e. 
//     if we insert the same value again as many times 
//     we want but it will be inserted only once 
//     set always arrange arrange itself in a sorted way
//     no matter the order in which you inserted */

//     s.insert(5);
//     s.insert(5);
//     s.insert(5);
//     s.insert(1);
//     s.insert(6);
//     s.insert(6);
//     s.insert(0);
//     s.insert(0);


//     for(auto i:s){
        
//         cout<<i<<endl;
//     }cout<<endl;

//     set<int>::iterator it=s.begin();
//     it++;

//     s.erase(it);

//     for(auto i : s){
//         cout<<i<<endl;
//     }cout<<endl;

//     cout<<" 5 is present or not "<<s.count(5)<<endl;

//     set<int>::iterator itr=s.find(5);

//     for(auto it=itr; it != s.end();it++){
//         cout<<*it<<" ";
//     }cout<<endl;

//      /*insert ,find ,erase & count all of these has complexity O(log n) */ 



// }



// int main(){

//     /******************MAP LIBRARY USE*****************/

//     map<int,string> m;

//     m[1]="babbar";
//     m[2]="kumar";
//     m[13]="love";

//     m.insert({5,"bheem"});

//     cout<<"before erase"<<endl;
//     for(auto i:m){
//         cout<<i.first<<" "<<i.second<<endl;
//     }cout<<endl;

//     cout<<"finding 13 "<<m.count(13)<<endl;

//     m.erase(13);
//     cout<<"after erase"<<endl;
//     for(auto i:m){
//         cout<<i.first<<" "<<i.second<<endl;
//     }cout<<endl;

//     auto it = m.find(5);
//     for(auto i=it;i != m.end();i++){
//         cout<<(*i).first<<endl;
//     }

    
    
//     /* erase insert find count these have comlexity O(log n)
//     and comlexity O(1) in unordered map
//     because map is impementing by RED BLACK TREE or BALANCED TREE 
//     bur in unordered map  it is implemented by using HASH TREE  */




// }




// int main(){

//      vector<int> v;
//      v.push_back(1);
//      v.push_back(3);
//      v.push_back(6);
//      v.push_back(7);

//      cout<<"finding 6 "<<binary_search(v.begin(),v.end(),6)<<endl;

//      cout<<" lower bound "<<lower_bound(v.begin(),v.end(),6)-v.begin()<<endl;
//      cout<<" upper bound "<<upper_bound(v.begin(),v.end(),4)-v.begin()<<endl;

//      int a=3;
//      int b=5;

//      cout<<"max "<<max(a,b)<<endl;
//      cout<<" min "<<min(a,b)<<endl;

//      swap(a,b);
//      cout<<endl<<" a "<<a<<endl;
//      string abcd = "abcd";
//      reverse(abcd.begin(),abcd.end());
//      cout<<"reversed string "<<abcd<<endl;

//      rotate(v.begin(),v.begin()+1,v.end());
//      cout<<"after rotate"<<endl;
//      for(int i:v){
//         cout<<i<<" ";
//      }

  
// }

int main(){

   int a[]={1,2,3};
   vector<int> b;
   for(int i=0;i<3;i++)
            {
                b[i]=a[i];
            }
   cout<<b[1];
}