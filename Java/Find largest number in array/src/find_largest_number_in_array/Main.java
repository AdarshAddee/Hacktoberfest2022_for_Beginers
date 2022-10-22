package find_largest_number_in_array;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        int temp, size;
        int array[] = {4,85,84,14,645,4,5,16 ,20, 25, 63, 96, 57};
        size = array.length;

        for(int i = 0; i<size; i++ ){
            for(int j = i+1; j<size; j++){
                if(array[i]>array[j]){
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
        System.out.println("Third largest element is:: "+array[size-1]);
    }
}
