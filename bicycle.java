public class Bicycle {
    int speed = 100;
    int gears = 3;
    int cadence = 40;

    public void printing(){
        System.out.println("Bicycle [cadence = "+cadence+" , speed = "+speed+" , gears = "+gears+" ] ");
    }
    public static void main(String [] args){
        Bicycle ob1 = new Bicycle();
        ob1.printing();
    }
}
