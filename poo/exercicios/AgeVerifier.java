// Com base na idade inserida, atribui a categoria "Menor de idade", "Adulto" ou "Idoso"

import java.util.Scanner;

public class AgeVerifier {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int age = scan.nextInt();
        if(age < 18) {
            System.out.println("Menor de idade");
        } else if (age <= 60) {
            System.out.println("Adulto");
        } else {
            System.out.println("Idoso");
        }
        scan.close();
    }
}