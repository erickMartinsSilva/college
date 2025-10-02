package provas.P2.prova24_2.questao1;

import java.util.Map;
import java.util.HashMap;
import java.util.Set;

public class Utils {
    public Map<String, CriaturaMarinha> retornaDados(Set<String> conjuntoCriaturas) throws FormatoIncorretoException {
        Map<String, CriaturaMarinha> mapaCriaturas = new HashMap<String, CriaturaMarinha>();

        for(String str : conjuntoCriaturas) {
            String[] entrada = str.split("#");
            if(entrada.length != 3) {
                throw new FormatoIncorretoException("ERRO: O formato da string " + str + " está incorreto.");
            }

            CriaturaMarinha c = new CriaturaMarinha(entrada[0], entrada[1], Integer.parseInt(entrada[2]));
            mapaCriaturas.put(entrada[0], c);
        }

        return mapaCriaturas;
    }
}
