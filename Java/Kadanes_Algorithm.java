public class Kadanes_Algorithm {


    static int MaxSubSumArray(int arr[]) {
        int currSum = 0;
        int MaxSum = 0;

        for (int i = 0; i < arr.length; i++) {
            currSum += arr[i];
            if (currSum > MaxSum) {
                MaxSum = currSum;
            }

            if (currSum < 0) {
                currSum = 0;
            }

        }
        return MaxSum;
    }

    public static void main(String[] args) {
        int[] arr = {-2, -3, 4, -1, 2, 1, 5, -3};

        int max = MaxSubSumArray(arr);
        System.out.println("Largest Sum : " + max);
    }
}
