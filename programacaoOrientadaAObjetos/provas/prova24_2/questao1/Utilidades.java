import java.util.List;
import java.util.ArrayList;

public class Utilidades {
    public static List getPalavroes() {
        List<String> palavroes = new ArrayList();
        return palavroes;
    }

    public static boolean moderar(String frase) {
        String[] fraseDividida = frase.split(' ');
        List<String> palavroes = Utils.getPalavroes();

        for(int i = 0; i < fraseDividida.length; i++) {
            for(int j = 0; j < palavroes.size(); j++) {
                if(fraseDividida[i].toLowerCase().equals(palavroes.get(j))) {
                    return true;
                }
            }
        }

        return false;
    }
}