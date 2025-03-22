import java.util.Scanner;

public class AgeVerifier {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int age = scan.nextInt();
        if(age < 18) {
            System.out.println("Menor de idade");
        } else if (age > 18 && age < 60) {
            System.out.println("Adulto");
        } else {
            System.out.println("Idoso");
        }
    }
}