// R: O código não compila, pois não há uma instância da classe Processa para chamar o metodo calcula.
// Uma possível correção é declarar calcula como static

package listas.lista4;

public class Processa {
    public static void main(String[] args) {
        System.out.println(calcula(2, 3));
    }
    public static double calcula(double a, double b) {
        return (a+b) * (a*0.1) + (b*0.9);
    }
}

