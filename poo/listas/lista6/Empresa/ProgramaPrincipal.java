package listas.lista6.Empresa;

import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

public class ProgramaPrincipal {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String[] array_funcionarios = new String[5];

        for(int i = 0; i < array_funcionarios.length; i++) {
            System.out.println("Funcionario " + (i+1));
            System.out.print("Insira as informações do funcionário (id#nome#salario#tipo): ");
            array_funcionarios[i] = scan.nextLine();
        }

        List listaFuncionarios = new ArrayList<>();
        listaFuncionarios = Utils.retornaDados(array_funcionarios);

        System.out.println("Funcionarios: ");
        for(int i = 0; i < listaFuncionarios.size(); i++) {
            System.out.println(listaFuncionarios.get(i));
        }

        Utils.mediaSalarial(listaFuncionarios);
    }
}
