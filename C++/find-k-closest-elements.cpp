static bool comp(pair<int,int> a, pair<int,int> b)
    {
        if(a.first < b.first)
            return false;
        if(a.first == b.first && a.second > b.second)
            return false;
        
        return true;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       vector<pair<int,int>> vp;
       vector<int> result;
        
       for(int i=0;i<arr.size();i++)
       {
           int z = abs(x-arr[i]);
           vp.push_back(make_pair(z,arr[i]));
       }
        
       sort(vp.begin(),vp.end());
        
       for(int i=0;i<vp.size();i++)
       {
           cout<<vp[i].first<<" "<<vp[i].second<<endl;
       }
       
       for(int i=0;i<k;i++)
       {
           result.push_back(vp[i].second);
       }
       
       sort(result.begin(),result.end());
        
       return result;
    }
