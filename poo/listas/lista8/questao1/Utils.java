package listas.lista8.questao1;

import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.Iterator;

public class Utils {
    public static boolean existe(List<Aluno> x, Aluno y) {
        return x.contains(y);
    }

    public static void ordena(List<Aluno> x) {
        Collections.sort(x);
    }

    public Map<String, Aluno> retornaDados(Set<String> conjuntoAlunos) {
        Map<String, Aluno> mapaAlunos = new HashMap<String, Aluno>();
        Iterator<String> i = conjuntoAlunos.iterator();

        while(i.hasNext()) {
            String[] entrada = i.next().split("#");

            if(entrada[3].equals("R")) {
                AlunoRegular r = new AlunoRegular(entrada[0]);
                r.setNome(entrada[1]);
                r.setNota(Double.parseDouble(entrada[2]));
                mapaAlunos.put(entrada[0], r);   
            } else if(entrada[3].equals("E")) {
                AlunoEspecial e = new AlunoEspecial(entrada[0]);
                e.setNome(entrada[1]);
                e.setNota(Double.parseDouble(entrada[2]));
                mapaAlunos.put(entrada[0], e);
            } else throw new RuntimeException("Tipo inválido para o aluno de ID " + entrada[0]);
        }

        return mapaAlunos;
    }
}
