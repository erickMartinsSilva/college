// Soma dois números
package exercicios;

import java.util.Scanner;

public class SumTwoNumbers {
    public static void main (String[] args) {
        int n1, n2, sum;
        Scanner scan = new Scanner(System.in);
        System.out.print("N1: ");
        n1 = scan.nextInt();
        System.out.print("N2: ");
        n2 = scan.nextInt();
        sum = n1 + n2;
        System.out.println("N1 + N2 = " + sum);
        scan.close();
    }
}