class Solution {
public:
    bool strongPasswordCheckerII(string s) {
        bool lower=false,special=false;
        bool upper=false,digit=false;
        bool same=false;
        int i=0;
        if(s.size()<8) return false;
        
         for(i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z') lower=true;
            if(s[i]>='A' && s[i]<='Z') upper=true;
            if(s[i]>='0' && s[i]<='9') digit=true;
        }
        
        //lets check special case
        
        string p="!@#$%^&*()-+";
        for(int i=0;i<p.size();i++){
           int temp=s.find(p[i]);
            if(temp>=0) 
                special=true;
            }
        //checking same char
        
       for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1] && i!=s.size()-1) return false;
             }
        
        if(special && lower && upper && digit )
            return true;
        else return false;
        
        
        
        
        
        
       
        
        
           
        }
    
};
