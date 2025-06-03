package listas.lista6.Empresa;
import java.util.List;
import java.util.ArrayList;

public class Utils {
    public static boolean existe(List x, Funcionario y) {
        return x.contains(y);
    }

    public static List retornaDados(String[] array_funcionarios) {
        List<Funcionario> newList = new ArrayList<>();

        for(int i = 0; i < array_funcionarios.length; i++) {
            String[] currentStr = array_funcionarios[i].split("#");
            if(currentStr[3].equals("A")) {
                AnalistaSistemas a = new AnalistaSistemas(currentStr[0]);
                a.setNome(currentStr[1]);
                a.setSalario(Double.parseDouble(currentStr[2]));
                newList.add(a);
            } else if(currentStr[3].equals("P")) {
                Programador p = new Programador(currentStr[0]);
                p.setNome(currentStr[1]);
                p.setSalario(Double.parseDouble(currentStr[2]));
                newList.add(p);
            }
        }

        return newList;
    }

    public static void mediaSalarial(List x) {
        int count_programador = 0, count_analista = 0;
        double soma_programador = 0, soma_analista = 0;

        for(int i = 0; i < x.size(); i++) {
            if(x.get(i) instanceof Programador) {
                Programador p = (Programador) x.get(i);
                soma_programador += p.getSalario();
                count_programador++;
            } else if(x.get(i) instanceof AnalistaSistemas) {
                AnalistaSistemas a = (AnalistaSistemas) x.get(i);
                soma_analista += a.getSalario();
                count_analista++;
            }
        }

        String mediaProgramadorFormatada = String.format("%.2f", (soma_programador/count_programador));
        String mediaAnalistaFormatada = String.format("%.2f", (soma_analista/count_analista));
        System.out.println("Media salarial dos programadores: R$" + mediaProgramadorFormatada);
        System.out.println("Media salarial dos analistas: R$" + mediaAnalistaFormatada);
    }
}
