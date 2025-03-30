// Conta quantos caracteres de cada tipo tem numa string

import java.util.Scanner;

public class HowManyChars {
    public static void main(String[] args) {
        String input;
        int letter = 0, space = 0, number = 0, other = 0;
        Scanner scan = new Scanner(System.in);

        System.out.print("Insert string: ");
        input = scan.nextLine();
        scan.close();
        int inputLen = input.toCharArray().length;

        for(int i = 0; i < inputLen; i++) {
            if((input.charAt(i) >= 65 && input.charAt(i) <= 90) || (input.charAt(i) >= 97 && input.charAt(i) <= 122)) {
                letter++;
            } else if(input.charAt(i) == ' ') {
                space++;
            } else if(input.charAt(i) >= 48 && input.charAt(i) <= 57) {
                number++;
            } else {
                other++;
            }
        }

        System.out.println("Letters: " + letter);
        System.out.println("Spaces: " + space);
        System.out.println("Numbers: " + number);
        System.out.println("Other: " + other);
    }
}