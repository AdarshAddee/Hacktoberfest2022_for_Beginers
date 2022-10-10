import java.util.Arrays;
import java.util.Scanner;

class NeighborExchange {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        String[] sequence = input.nextLine().split(" ");

        int size = sequence.length;

        int[] numbers = new int[sequence.length];
        for (int i = 0; i < sequence.length; i++) {
            numbers[i] = Integer.parseInt(sequence[i]);
        }

        if (size % 2 != 0) {
            size -= 1;
        }

        for (int i = 0; i < size; i += 2) {
            int aux = numbers[i];
            numbers[i] = numbers[i + 1];
            numbers[i + 1] = aux;
        }

        System.out.println(Arrays.toString(numbers));
    }
}