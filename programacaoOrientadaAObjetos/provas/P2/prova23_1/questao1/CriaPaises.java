package provas.P2.prova23_1.questao1;

import java.util.List;
import java.util.ArrayList;

public class CriaPaises {
    public int contaHashtag(String str) {
        int count = 0;
        String[] strDividida = str.split("");

        for(String s : strDividida) {
            if(s.equals("#")) {
                count++;
            }
        }

        return count;
    } 

    public List<Pais> retornaPaises() {
        List<Pais> listaPaises = new ArrayList<Pais>();

        Pais can = new Pais("can", "Canadá", 10000000);
        can.setPopulacao(40000000);
        Pais usa = new Pais("usa", "Estados Unidos", 9800000);
        usa.setPopulacao(340000000);
        Pais mex = new Pais("mex", "México", 2000000);
        mex.setPopulacao(130000000);
        can.atribuirFronteira(usa);
        usa.atribuirFronteira(can);
        usa.atribuirFronteira(mex);
        mex.atribuirFronteira(usa);

        listaPaises.add(can);
        listaPaises.add(usa);
        listaPaises.add(mex);

        return listaPaises;
    }

    public List<Pais> retornaPaises(String[] arrayPaises) throws FormatoIncorretoException {
        List<Pais> listaPaises = new ArrayList<Pais>();

        for(String str : arrayPaises) {
            int numHashtags = contaHashtag(str);
            if(numHashtags != 3) throw new FormatoIncorretoException(str, numHashtags);
            
            String[] entrada = str.split("#");
            Pais p = new Pais(entrada[0], entrada[1], Double.parseDouble(entrada[2]));
            p.setPopulacao(Integer.parseInt(entrada[3]));
            listaPaises.add(p);
        }

        return listaPaises;
    }
}
