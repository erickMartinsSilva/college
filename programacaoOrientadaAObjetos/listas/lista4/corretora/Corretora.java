package listas.lista4.corretora;
import java.util.Scanner;

public class Corretora {
    public static double somaImoveis(Imovel[] c1) {
        double soma = 0;
        for (Imovel imovel : c1) {
            soma += imovel.getPreco();
        }
        return soma;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Imovel[] c1 = new Imovel[5];

        for(int i = 0; i < c1.length; i++) {
            String endereco, preco;

            c1[i] = new Velho();
            System.out.println("Imovel " + (i+1));
            System.out.print("Endereco: ");
            endereco = scan.nextLine();
            c1[i].setEndereco(endereco);
            System.out.print("Preco: R$");
            preco = scan.nextLine();
            c1[i].setPreco(Double.parseDouble(preco));
        }

        double soma = somaImoveis(c1);
        System.out.println("Soma dos imóveis: R$" + soma + "0");
    }
}
