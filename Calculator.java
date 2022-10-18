import java.util.Scanner;
public class Calculator {

	public static void main(String[] args) {
		
		float num1, num2, num3 ;
		int choice, n;
		System.out.println("1. Addition");
		System.out.println("2. Subtraction");
		System.out.println("3. Multiplication");
		System.out.println("4. Division");
		System.out.println("5. Exit");
		
		do {
			//create an object of scanner class
			Scanner input = new Scanner(System.in);
			System.out.println("Enter first number: ");
      
      //input from user
			num1 = input.nextFloat();
			
			System.out.println("Enter second number: ");
      //input from user
			num2 = input.nextFloat();
			
			System.out.println("Enter choice: ");
      //input from user
			choice = input.nextInt();
			
			switch(choice) {
			case 1:  
				num3 = num1 + num2;//addition
				System.out.println(num3);
				break;
			case 2:
				num3 = num1 - num2;//subtraction
				System.out.println(num3);
				break;
			case 3: 
				num3 = num1 * num2;//multiplication
				System.out.println(num3);
				break;
			case 4:
				num3 = num1 / num2;//divivsion
				System.out.println(num3);
				break;
			case 5:
				System.exit(0);
				
			default:
				System.out.println("Invalid Choice");

			}
			System.out.println("Do you want to continue: 1.Yes   2.No");
			n = input.nextInt();
		}
		while(n==1);
		
		System.out.println("ThankYou!!");

	}

}
