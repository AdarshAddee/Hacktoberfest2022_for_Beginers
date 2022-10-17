class Solution {
public:
    void nextPermutation(vector<int>& ARR)
    {
        int N=ARR.size();
        int i,j;
        for(i=N-2;i>=0;i--)
        {
            if(ARR[i]<ARR[i+1])
                break;
        }
        if(i<0)reverse(ARR.begin(),ARR.end());
        else
        {
            for(j=N-1;j>i;j--)
            {
                if(ARR[i]<ARR[j])
                    break;
            }
            swap(ARR[i],ARR[j]);
            reverse(ARR.begin()+i+1,ARR.end());
        }
        
    }
};
