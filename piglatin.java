import java.util.*;
class piglatin
{ 
    public static void main()
    {
        Scanner sc= new Scanner(System.in);
        System.out.println("enter a string");
        String str= sc.nextLine();
        int x,y;
        String str1,str2;
        char b;b=0;
        x=str.length();
        System.out.println("the piglatin word of the string");
        for(y=0;y<=x;y++)
        { 
            b=(str.charAt(y));
            if(b=='a'||b=='e'||b=='i'||b=='o'||b=='u'||b=='A'||b=='E'||b=='O'||b=='I'||b=='U')
            break;
        }
    str1=str.substring(y,x);
    str2=str.substring(0,y);
    System.out.println(str1+str2+"ay");
}
}
    
        
            
        
    


    

