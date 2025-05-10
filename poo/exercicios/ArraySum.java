// Exibe a soma dos elementos do array [1,2,3,4,5]

public class ArraySum {
    public static int arraysum(int[] arr) {
        int sum = 0;
        for (int i : arr) {
            sum += i;
        }
        return sum;
    }
    public static void main(String[] args) {
        int[] arr = new int[]{1, 2, 3, 4, 5};
        System.out.println(arraysum(arr));
    }
}
