#include <iostream>
#include<vector>
using namespace std;

void transpose(vector<vector<int>>vec){

    for(int i=0;i<vec.size();i++){
        for (int j=0;j<i;j++){
            int a = vec[i][j];
            vec[i][j]=vec[j][i];
            vec[j][i]=a;

        }
    }
    for (int i=0;i<vec.size();i++){
            for (int j=0;j<vec.size();j++){
                    cout<<vec[i][j]<<" ";
            }
            cout<<endl;
    }
}

int main(){
    vector<vector<int>>vec ={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    for (int i=0;i<vec.size();i++){
        for (int j=0;j<vec.size();j++){
                cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    transpose(vec);
}
