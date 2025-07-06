package listas.lista8.questao2;

import java.util.Map;
import java.util.HashMap;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Map<String, Integer> mapa = new HashMap<String, Integer>();
        mapa.put("A1", 5);
        mapa.put("A2", 6);
        mapa.put("A3", 7);
        mapa.put("BD21", 3);
        mapa.put("B2", 7);
        mapa.put("AC74", 2);
        mapa.put("A5", 8);
        mapa.put("B3", 3);

        System.out.println(contaA(mapa));
    }

    public static double contaA(Map<String, Integer> mapa) {
        Set<String> keys = mapa.keySet();
        double soma = 0;

        for(String key : keys) {
            if(key.charAt(0) == 'A') {
                soma += mapa.get(key);
            }
        }

        return soma;
    }
}
