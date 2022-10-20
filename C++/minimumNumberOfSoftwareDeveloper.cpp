

#include<bits/stdc++.h>
using namespace std;
vector<int> sol;
void solution(vector<int> &people,int nSkill,int cp,vector<int> &oneSol,int sMask){
    if(cp == people.size()){
        if(sMask==((1<<nSkill)-1)){
            if(sol.size()==0 or oneSol.size()<sol.size()){
                sol=oneSol;
            }
        }
        return;
    }
    solution(people,nSkill,cp+1,oneSol,sMask);
    oneSol.push_back(cp);
    solution(people,nSkill,cp+1,oneSol,(sMask | people[cp]));
    oneSol.pop_back();
}
int main(){
    int n; // total number of skills...
    cin>>n;
    unordered_map<string,int> sm; // skill map...
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        sm[x]=i;
    }
    int np;
    cin>> np; // number of people...
    vector<int> people(np);
    for(int i=0;i<np;i++){
        int personSkills;
        cin>>personSkills;
        for(int j=0;j<personSkills;j++){
            string skill;
            cin>>skill;
            int sNum = sm[skill];
            people[i]=people[i] | (1<<sNum);
        }
    }
    vector<int> solN;
    solution(people,n,0,solN,0);
    cout<<"[";
    for(int i=0;i<sol.size();i++){
        if(i==sol.size()-1){
            cout<<sol[i];
        }else{
            cout<<sol[i]<<", ";
        }
    }
    cout<<"]";
    return 0;
}

// 5
// a b c d e
// 4
// 2
// a c
// 2
// b d
// 4
// a b c d
// 1
// e
