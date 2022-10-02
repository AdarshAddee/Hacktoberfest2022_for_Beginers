public class HappyNumber {
    public boolean isHappy(int n) {
        int s = n;
        int f = n;
        do {
            s = findno(s);
            f = findno(findno(f));
        }while(s != f);
        
        if(s == 1){
            return true ;
        }
      return false;
        
        
    }
    public int findno(int n){
        int h =n;
    int ans =0;
        while(h > 0){
            int j = h %10;
            ans += j*j;
            h /=10;
        }
        return ans;
    }
}
