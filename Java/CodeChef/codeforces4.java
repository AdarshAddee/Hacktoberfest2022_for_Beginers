import java.util.*;
public class codeforces4 {
    public static void main(String[] args) {
        Scanner sc =  new Scanner(System.in);
        String str = sc.nextLine();
        String str1 = "";
        for(int i=0;i<str.length();i++){
            char ch = str.charAt(i);
            
            if(ch == '.' ){
                str1 = str1+"0";
                continue;
            }
            char ch1 = str.charAt(i+1);
              
           if(ch == '-' && ch1 == '.'){
                str1 = str1+"1";
                i++;
            }
               
            if(ch == '-' && ch1 == '-'){
                str1 = str1 + "2";
                i++;
            }
                
        }
    
        System.out.println(str1);
    }
}
