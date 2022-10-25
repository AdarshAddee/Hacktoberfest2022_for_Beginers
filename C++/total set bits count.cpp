int countSetBits(int n)
    {
        if(n==0)
        return 0;
        if(n==1)
        return 1;
        int k=floor(log2(n));
        return (pow(2,k-1)*k)+(n-pow(2,k)+1)+countSetBits(n-pow(2,k));
    }
