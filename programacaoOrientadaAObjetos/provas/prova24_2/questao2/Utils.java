package provas.prova24_2.questao2;

import java.util.List;

public class Utils {
    public static boolean existe(List<?> lista, Planta planta) {
        return lista.contains(planta);
    }
    public static Planta[] ordena(List<Planta> lista) {
        Planta[] listaOrdenada = lista.toArray(new Planta[0]);
        Planta aux;

        for(int i = 0; i < listaOrdenada.length - 1; i++) {
            for(int j = i + 1; j < listaOrdenada.length; j++) {
                if(listaOrdenada[i].getTamanho() > listaOrdenada[j].getTamanho()) {
                    aux = listaOrdenada[i];
                    listaOrdenada[i] = listaOrdenada[j];
                    listaOrdenada[j] = aux;
                }
            }
        }

        return listaOrdenada;
    }
}