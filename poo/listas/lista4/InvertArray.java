package listas.lista4;
import java.util.Arrays;

public class InvertArray {
    public static void invertArray(int[] array) {
        for(int i = 0; i < array.length / 2; i++) {
            int temp = array[i];
            array[i] = array[array.length - 1 - i];
            array[array.length-1-i] = temp;
        }
    }

    public static void main(String[] args) {
        int[] array = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
        invertArray(array);
        System.out.println(Arrays.toString(array));
    }
}
