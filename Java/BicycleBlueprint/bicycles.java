class cycles {
    int gear;
    int Cadence;
    int speed;

    void change_gear(int newValue) {
        gear = newValue;
    }

    void change_Cadence(int newValue) {
        Cadence = newValue;
    }

    void speedUp(int increment) {
        speed = speed + increment;
    }

    void applyBrakes(int decrement) {
        speed = speed - decrement;
    }

    void printStates(){
        System.out.println("gear" +gear + " " + "cadence" + Cadence + " "+ "speed" + speed);
    }

}

public class bicycles {
    public static void main(String[] args) {
        
    
cycles  bike1 = new cycles();
cycles  bike2 = new cycles();

bike1.change_Cadence(45);
bike1.change_gear(4);
bike1.speedUp(53);
bike1.change_gear(2);
bike1.printStates();



bike2.change_Cadence(85);
bike2.change_gear(6);
bike2.speedUp(93);
bike2.change_Cadence(43);
bike2.applyBrakes(43);
bike2.speedUp(33);
bike2.printStates();

}
}
