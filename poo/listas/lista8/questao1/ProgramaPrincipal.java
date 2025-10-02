package listas.lista8.questao1;

import java.util.Scanner;
import java.util.Map;
import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;

public class ProgramaPrincipal {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Utils utils = new Utils();
        Set<String> conjuntoAlunos = new HashSet<String>();

        for(int i = 0; i < 2; i++) {
            System.out.print("Insira alunos (formato: id#nome#nota#tipo): ");
            String entrada = scan.nextLine();
            conjuntoAlunos.add(entrada);
        }

        try {
            Map<String, Aluno> mapaAlunos = utils.retornaDados(conjuntoAlunos);
            List<Aluno> listaAlunos = new ArrayList<Aluno>(mapaAlunos.values());

            Utils.ordena(listaAlunos);

            for(int i = 0; i < listaAlunos.size(); i++) {
                System.out.println(listaAlunos.get(i));
            }
        } catch(RuntimeException e) {
            System.out.println("ERRO: " + e.getMessage());
        }

        scan.close();
    }
}
