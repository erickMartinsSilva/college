package provas.P1.prova24_2.questao1;

import java.util.List;
import java.util.ArrayList;

public class Utilidades {
    public static List getPalavroes() {
        List<String> palavroes = new ArrayList();
        return palavroes;
    }

    public static boolean moderar(String frase) {
        String[] fraseDividida = frase.split(" ");
        List<String> palavroes = Utilidades.getPalavroes();

        for(int i = 0; i < fraseDividida.length; i++) {
            if(palavroes.contains(fraseDividida[i].toLowerCase())) {
                return true;
            }
        }

        return false;
    }
}