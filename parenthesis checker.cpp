bool ispar(string x)
    {
        // Your code here
        int n=x.length();
        stack<char> st;
        //st.push(x[0]);
        for(int i=0;i<n;i++){
            if(x[i]=='(' || x[i]=='{' || x[i]=='[')
            st.push(x[i]);
            else if(x[i]==')'){
                if((!st.empty()) && (st.top()=='('))
                st.pop();
                else
                return false;
            } 
            else if(x[i]==']'){
                if((!st.empty()) && (st.top()=='['))
                st.pop();
                else
                return false;
            } 
            else if(x[i]=='}'){
                if((!st.empty()) && (st.top()=='{'))
                st.pop();
                else
                return false;
            }
        }
        if(st.empty())
        return true;
        return false;
    }
