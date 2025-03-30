// Calculadora simples para realizar operações aritméticas com dois números

import java.util.Scanner;

public class Calculator {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n1, n2, result;
        String input;

        System.out.print("Enter first number: ");
        n1 = scan.nextInt();
        System.out.print("Enter second number: ");
        n2 = scan.nextInt();
        System.out.print("Select operation(+, -, *, /): ");
        input = scan.next();

        if(input.length() == 1) {
            char operation = input.charAt(0);
            switch(operation) {
                case '+': 
                    result = n1 + n2; 
                    System.out.println(result);
                    break;
                case '-': 
                    result = n1 - n2; 
                    System.out.println(result);
                    break;
                case '*': 
                    result = n1 * n2; 
                    System.out.println(result);
                    break;
                case '/': 
                    result = n1 / n2;
                    System.out.println(result);
                    break;
                default: System.out.println("Error: Invalid operation"); break;
            }
        } else {
            System.out.println("Error: Invalid operation");
        }
        scan.close();
    }
}