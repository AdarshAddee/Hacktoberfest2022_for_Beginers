package hierarchical;
//Jan 19, 2021
//All Copyright © goes to Hamim Reza Shammo (https://github.com/hrshammo/)
class A {
    int i;
    void show(int a){
        i=a;
        System.out.println(i);
    }
}
class B extends A {
    int j;
    void show2(int a, int b){
        i=a;
        j=b;
        System.out.println(i+j);
    }
}
class C extends B {
    int k;
    void show3(int a, int b, int c){
        i=a;
        j=b;
        k=c;
        System.out.println(i+j+k);
    }
}

public class Main {

    public static void main(String[] args) {
	// write your code here
        B ob=new B();
        ob.show2(10,20);
        C ob2=new C();
        ob2.show3(10,20,30);
    }
}
