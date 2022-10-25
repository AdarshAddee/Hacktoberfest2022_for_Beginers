// Github username: piumir3
// Aim: Your Repo aim according to your program
// Date: oct 25 2022

// start coding


public class Simplesortingapp {

    /
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
             
        SimpleSorting k = new SimpleSorting(7);
        k.insert(4);
        k.insert(8);
        k.insert(1);
        k.insert(3);
       k.display();
       k.bubbleSort();
       k.display();
       k.selectionSort();
       k.display();
       k.insertionSort();
       k.display();
    }
    
}

class SimpleSorting {
 private int[] a;//ref to array a
 private int nElems;//number of data items
 //------------------------------------------------------
 public SimpleSorting(int max) {
     this.a=new int[max];
     this.nElems=0;
 }
 
 public void insert(int value){
     if(nElems==a.length){
         System.out.println("Array is full");
         return;
     }
     this.a[this.nElems]=value;
     this.nElems++;
 }
 
 public void display(){
     System.out.println("Array content");
     for(int i = 0; i< this.nElems; i++){
         System.out.print(this.a[i] + " ");
     }
     System.out.println();
 }
 
 private void swap(int index1, int index2)
 {
    int temp;
    temp=a[index1];
    a[index1]=a[index2];
    a[index2]=temp;
 }
 
 public void bubbleSort() {
     for(int i = 0; i<nElems-1; i++){
     for(int j = 0; j<(nElems-1)-i; j++){
     if(a[j]>a[j+1]){
     swap(j, j+1);
     }
     }
     }
     System.out.println("this is sort using bubble sort");
 }
 
 public void selectionSort() {
     for(int i =0; i<nElems; i++){
     int minIndex=i;
     for(int j=i+1; j<nElems; j++){
     if(a[j]<a[minIndex]){
         minIndex=j;
     }
     }
      swap(i,minIndex);
     }
     System.out.println("numbers are sort with selection sort");
 }
 
 public void insertionSort() {
    for( int i=1;i<nElems; i++){
    int key = a[i];
    int j=i-1;
    while(j>=0){
    if(a[j]>key){
    a[j+1]=a[j];
    }else{
    break;
    }
    j--;
    }
    a[j+1]=key;
    }
     System.out.println("sort with insertion");
 }
}
