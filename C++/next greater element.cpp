vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> v;
        v.push_back(-1);
        stack<long long> st;
        st.push(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            while(st.empty()==false && st.top()<=arr[i])
            st.pop();
            long long r=(st.empty())?(-1):(st.top());
            v.push_back(r);
            st.push(arr[i]);
        }
        reverse(v.begin(),v.end());
        return v;
    }
