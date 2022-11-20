// Github username: GutsMusahi
// Aim: Hashing
// Date: 16-11-2022


import java.util.*;
/*
*@author kamal
*/


public class Hashing {

    //intializers
    static int hashsize;
    static int[] hashtable;
    static class LinkedHashEntry{
         int value;
         LinkedHashEntry next;
         //Constructor
          public LinkedHashEntry( int value){
             this.value = value;
             this.next = null;
         }
     }
    static LinkedHashEntry[] chainhashtable;
  

   
  public static void linearProb(int[] a, int key, int pos) {
        while(true){
            pos++;
            pos = pos % a.length;
            
            if(a[pos]==0){
                break;
            }

        }
        a[pos]=key;

    }

   

    public static void sepChain(LinkedHashEntry[] a, int key, int pos) {
        LinkedHashEntry node = new LinkedHashEntry(key);
        node.next = chainhashtable[pos];
        chainhashtable[pos]=node;
    }

    public static void insertModulo(int key) {
        if (hashtable[findModulo(key)]==0){
            hashtable[findModulo(key)] = key;
        }
        else{
            linearProb(hashtable,key,findModulo(key));

        }

    }

    public static void deleteModulo(int key) {
        int pos=key% hashsize;
        if (hashtable[pos] == key){
            hashtable[pos] = 0;
        }else{
            while(true){
                pos++;
                pos = pos % hashsize;
                if (hashtable[pos] == key){
                    break;
                }
            hashtable[pos] = 0;
            }
        }


    }

    public static int[] displayModulo() {
       return hashtable;

    }

    public static int findModulo(int key) {
        return key % hashsize;

    }

    public static void insertMidSquare(int key) {
        if(chainhashtable[findMidSquare(key)]==null){
            chainhashtable[findMidSquare(key)]=new LinkedHashEntry(key);
        }else{
            sepChain(chainhashtable,key,findMidSquare(key));
        }
      
    }


    public static int findMidSquare(int key) {
        key=key*key;
        
        //determines the total number of digits or length of the given number  
        int total_digits = (int)Math.log10(key) + 1;  
        //determines the middle digit  
        key = (int)(key / Math.pow(10, total_digits / 2)) % 10;  
        //returns the mid digit  
        
        return key ;  

    }

    public static LinkedHashEntry[] displayMidSquare() {
        return chainhashtable;

    }

   public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);   
        System.out.println("1. Hash table using (modulo division method) and apply ((linear probing)) when collision occurs");
        System.out.println("2. Hash table using (mid square method) and apply ((separate chaining)) when collision occurs");
        int choice = 0;
        
        while (true) {
            System.out.println("Enter your choice:");
             choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("Enter the size of Hashtable:");
                    hashsize = sc.nextInt();
                    hashtable = new int[hashsize];
                    System.out.println("Enter all the elements to insert using modulo in HASHTABLE---");

                    for (int i = 0; i < hashsize; i++) {
                    insertModulo(sc.nextInt());
                    }

                    System.out.println();
                    int[] arr1 = displayModulo();    //invoking method and storing returned array into arr
                    System.out.println("divisionModulo Hashtable is :") ; 
                    System.out.println(Arrays.toString(arr1));   //returns the string representation of the object  
                    System.out.println();
                break;

                case 2:
                    System.out.println("Enter the size of Hashtable:");
                    hashsize = sc.nextInt();
                    String str =  sc.nextLine();

                    chainhashtable = new LinkedHashEntry[hashsize];
                    System.out.println("Enter all the elements to insert using midsquare in HASHTABLE---");
                    String str1 =  sc.nextLine();

                    try {
                        while(!(str1).isEmpty()){
                            int number = Integer.parseInt(str1);
                        
                            insertMidSquare(number);
                        
                            str1 = sc.nextLine();
                        }
                    }
                     catch (NumberFormatException e) {
                         System.out.println("There was an exception. You entered a data type other than Integer");
                        }

                    LinkedHashEntry[] arr2 = displayMidSquare();    //invoking method and storing returned array into arr
                    System.out.println(" midSquare Hashtable is :") ;
                    
                    //returns the string representation of the object  
                    
                    for (int i = 0; i < arr2.length; i++){
                        System.out.print ("Bucket " + i + ":  ");             
                        LinkedHashEntry start = arr2[i];
                        while(start != null){
                            System.out.print(start.value +" ");
                            start = start.next;
                        }
                        System.out.println();   
                    }
                break;
            
                default:
                    break;
            }
            
          
        
      

        
    }
}
}
