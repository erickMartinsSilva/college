// Calcula a média dos argumentos inseridos pelo usuário, sendo eles dois números inteiros

public class CalcMedia {
    public static void main(String[] args) {
        int x = Integer.parseInt(args[0]), y = Integer.parseInt(args[1]), media = (x+y)/2;
        System.out.println(media);
    }
}