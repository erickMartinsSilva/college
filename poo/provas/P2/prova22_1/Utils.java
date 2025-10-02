package provas.P2.prova22_1;

import java.util.Collection;
import java.util.Collections;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.List;
import java.util.Iterator;

public class Utils {

    public static boolean existe(Collection<CorpoCeleste> x, CorpoCeleste y) {
        return x.contains(y);
    }

    public static void ordena(List<CorpoCeleste> x) {
        Collections.sort(x);
    }

    public Map<String, CorpoCeleste> retornaDados(Set<String> conjuntoCorpos) throws FormatoIncorretoException {
        Map<String, CorpoCeleste> mapaCorposCelestes = new HashMap<String, CorpoCeleste>();
        Iterator<String> str = conjuntoCorpos.iterator();

        while(str.hasNext()) {
            String[] entrada = str.next().split("");
            if(entrada.length != 4) {
                throw new FormatoIncorretoException(str.next());
            }

            if(entrada[3].equals("P")) {
                Planeta p = new Planeta(entrada[0]);
                p.setNome(entrada[1]);
                p.setDistancia(Double.parseDouble(entrada[2]));
                mapaCorposCelestes.put(entrada[0], p);
            }
            if(entrada[3].equals("E")) {
                Estrela e = new Estrela(entrada[0]);
                e.setNome(entrada[1]);
                e.setDistancia(Double.parseDouble(entrada[2]));
                mapaCorposCelestes.put(entrada[0], e);
            }
        }

        return mapaCorposCelestes;
    }
}
