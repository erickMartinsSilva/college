package provas.P2.prova24_2.questao1;

import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Set<String> conjuntoCriaturas = new HashSet<String>();

        for(int i = 0; i < 3; i++) {
            System.out.print("Insira uma criatura (formato: tag#nomeEspecie#profundidade): ");
            conjuntoCriaturas.add(scan.nextLine());
        }

        try {
            Map<String, CriaturaMarinha> mapaCriaturas = new Utils().retornaDados(conjuntoCriaturas);
            System.out.println(mapaCriaturas);
        } catch(FormatoIncorretoException e) {
            System.out.println(e.getMessage());
        }

        scan.close();
    }
}
