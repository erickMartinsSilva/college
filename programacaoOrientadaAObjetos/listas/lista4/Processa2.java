// R: O código compila pois o metodo calcula esta sendo referenciado por meio de uma instância da classe Processa2.

package listas.lista4;

public class Processa2 {
    public static void main(String[] args) {
        System.out.println(new Processa2().calcula(2,3));
    }
    public double calcula(double a, double b) {
        return (a+b) * (a*0.1) + (b*0.9);
    }
}