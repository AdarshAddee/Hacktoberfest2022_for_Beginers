// ------ BALANCED BRACKETS -------------
// #include<bits/stdc++.h>
// using namespace std;

// unordered_map<char,int> symbols = {{'[',-1},{'(',-2},{'{',-3},{']',1},{')',2},{'}',3}};

// string isBalanced(string s) {
//     stack<char>st;
//     for(char bracket : s){
//         if(symbols[bracket]<0){
//             st.push(bracket);
//         }
//         else{
//             if(st.empty()) return "NO";
//             char top = st.top();
//             st.pop();
//             if(symbols[top] + symbols[bracket]!=0){
//                 return "NO";
//             }
//         }
//     }
//     if(st.empty()){
//         return "YES";
//     }
//     return "NO";

// }

// int main(){
//     int turn;cin>>turn;
//     while(turn--){
//         string s;
//         cin>>s;
//         cout<<isBalanced(s)<<endl;
//     }
//     return 0;
// }

//--------- NEXT GREATER ELEMENT -----------
//Question: Suppose we are given an array [4,5,2,25,7,8]
//For each element,write next greater element on right of that element or replace
//with -1
//Here our required output: [5,25,25,-1,8,-1]

#include<bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int> v){
    vector<int> nge(v.size());
    stack<int> st;
    for (int i = 0; i < v.size(); i++)
    {
        while (!st.empty() && v[i]>v[st.top()])
        {
            nge[st.top()] = i;
            st.pop();
        }
        st.push(i);  
    }
    while(!st.empty()){
        nge[st.top()] = -1;
        st.pop();
    }
    return nge;
    

}

int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    vector<int> nge = NGE(v);
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" "<<(nge[i] == -1 ? -1 : v[nge[i]])<<endl;
    }
    
    return 0;
}