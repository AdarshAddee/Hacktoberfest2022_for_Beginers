public class Tower_of_Hanoi {
    
     public static void main(String[] args) {
        towerOfHanoi(3, 'A', 'B', 'C');
    }
    
    public static void towerOfHanoi(int n, char from, char to, char aux) {
        if (n == 1) {
            System.out.println("Move disk 1 from " + from + " to " + to);
            
        }else {
            towerOfHanoi(n - 1, from, aux, to);
        
            System.out.println("Move disk " + n + " from " + from + " to " + to);
        
            towerOfHanoi(n - 1, aux, to, from);
        }
    }   
}
